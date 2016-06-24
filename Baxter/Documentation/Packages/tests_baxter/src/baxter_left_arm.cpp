#include <ros/ros.h>
#include "baxter_left_arm.h" 

#include "std_msgs/Bool.h"

#include "baxter_core_msgs/JointCommand.h"
#include "baxter_core_msgs/EndEffectorCommand.h"

#include "sensor_msgs/Range.h"
#include "sensor_msgs/JointState.h"
#include "baxter_core_msgs/EndpointState.h"
#include "baxter_core_msgs/EndEffectorState.h"

#include "baxter_core_msgs/SolvePositionIK.h"
#include "geometry_msgs/PoseStamped.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Point.h"
#include "geometry_msgs/Quaternion.h"

#define PI 3.1416

// Constructeur
Baxter_left_arm::Baxter_left_arm(ros::NodeHandle noeud) 
{
	//Pub
	pub_joint_cmd = noeud.advertise<baxter_core_msgs::JointCommand>("/robot/limb/left/joint_command", 1);
	pub_gripper_cmd = noeud.advertise<baxter_core_msgs::EndEffectorCommand>("/robot/end_effector/left_gripper/command", 1);
	pub_prise_effectuee = noeud.advertise<std_msgs::Bool>("/pont_BaxterLigneTransitique/left_arm/prise_effectuee", 1);
	pub_attente_prise = noeud.advertise<std_msgs::Bool>("/pont_BaxterLigneTransitique/left_arm/attente_prise", 1);

	//Sub
	sub_joint_states = noeud.subscribe("/robot/joint_states", 1, &Baxter_left_arm::Callback_joint_states,this);
	sub_endpoint_state = noeud.subscribe("/robot/limb/left/endpoint_state", 1, &Baxter_left_arm::Callback_endpoint_state,this);
	sub_gripper_state = noeud.subscribe("/robot/end_effector/left_gripper/state", 1, &Baxter_left_arm::Callback_gripper_state,this);
	sub_ir_range = noeud.subscribe("/robot/range/left_hand_range", 1, &Baxter_left_arm::Callback_ir_range,this);
	sub_prise_demandee = noeud.subscribe("/pont_BaxterLigneTransitique/left_arm/prise_demandee", 1, &Baxter_left_arm::Callback_prise_demandee,this);

	//Srv
	client_inverse_kinematics = noeud.serviceClient<baxter_core_msgs::SolvePositionIK>("/ExternalTools/left/PositionKinematicsNode/IKService");

	// commande en mode position
	msg_JointCommand.mode = baxter_core_msgs::JointCommand::POSITION_MODE;
	//POSITION_MODE / VELOCITY_MODE / TORQUE_MODE / RAW_POSITION_MODE pour changer le mode

	// Initialisation du message de commande des angles
  	msg_JointCommand.names.push_back("left_s0");
  	msg_JointCommand.names.push_back("left_s1");
  	msg_JointCommand.names.push_back("left_e0");
  	msg_JointCommand.names.push_back("left_e1");
  	msg_JointCommand.names.push_back("left_w0");
  	msg_JointCommand.names.push_back("left_w1");
  	msg_JointCommand.names.push_back("left_w2");
	
	msg_JointCommand.command.resize(msg_JointCommand.names.size());

	// Angles en position 0
	for(size_t i = 0; i < msg_JointCommand.names.size(); i++) msg_JointCommand.command[i] = 0.0;

	// Initialisation commande pince
	msg_EndEffectorCommand.id = 65538;
  	msg_EndEffectorCommand.command = msg_EndEffectorCommand.CMD_RELEASE; // Ouverte


	// Initialisation capteurs //

	jointState.position.resize(17);
	jointState.velocity.resize(17);
	jointState.effort.resize(17);

	for(size_t i = 0; i < 17; i++)
	{
		jointState.position[i]=0;
		jointState.velocity[i]=0;
		jointState.effort[i]=0;
	}

	msg_prise_demandee.data = false ;
	msg_prise_effectuee.data = false ;  
	msg_attente_prise.data = false ; 
}


// Destructeur
Baxter_left_arm::~Baxter_left_arm()
{
}


// Callbacks

void Baxter_left_arm::Callback_joint_states(const sensor_msgs::JointState& msg)
{
	jointState = msg ;
	//std::cout<<msg<<std::endl;
}

void Baxter_left_arm::Callback_endpoint_state(const baxter_core_msgs::EndpointState& msg)
{
	endpointState = msg ;
	//std::cout<<msg<<std::endl;
}


void Baxter_left_arm::Callback_gripper_state(const baxter_core_msgs::EndEffectorState& msg)
{
	endEffectorState = msg ;
	//std::cout<<msg<<std::endl;
}

void Baxter_left_arm::Callback_ir_range(const sensor_msgs::Range& msg)
{
	//std::cout<<msg<<std::endl;
}

void Baxter_left_arm::Callback_prise_demandee(const std_msgs::Bool& msg)
{
	msg_prise_demandee = msg ;
	//std::cout<<msg<<std::endl;
}




// Envoie des commandes

void Baxter_left_arm::Update()
{
	pub_joint_cmd.publish(msg_JointCommand);
	pub_gripper_cmd.publish(msg_EndEffectorCommand);
	pub_prise_effectuee.publish(msg_prise_effectuee);
	pub_attente_prise.publish(msg_attente_prise);
}



// Commandes pince


void Baxter_left_arm::Grip(){msg_EndEffectorCommand.command = msg_EndEffectorCommand.CMD_GRIP;} // Fermée
void Baxter_left_arm::Release(){msg_EndEffectorCommand.command = msg_EndEffectorCommand.CMD_RELEASE;} // Ouverte

// Commande bras

void Baxter_left_arm::Position(float left_s0, float left_s1, float left_e0, float left_e1, float left_w0, float left_w1, float left_w2)
{
	// commande en mode position
	msg_JointCommand.mode = baxter_core_msgs::JointCommand::POSITION_MODE;
	
	msg_JointCommand.command[0] = left_s0;
	msg_JointCommand.command[1] = left_s1;
	msg_JointCommand.command[2] = left_e0;
	msg_JointCommand.command[3] = left_e1;
	msg_JointCommand.command[4] = left_w0;
	msg_JointCommand.command[5] = left_w1;
	msg_JointCommand.command[6] = left_w2;
}

void Baxter_left_arm::Position(float angle,int num)
{
	for(size_t i = 2; i < 8; i++) msg_JointCommand.command[i-2] = jointState.position[i];
	msg_JointCommand.command[num] = angle;
}





// Vague

void Baxter_left_arm::Position_sinu(float position,float compteur)
{
	float d[3] ;

	for(size_t i = 1; i <= 3; i++) d[i-1] = sin(compteur+(i*2*PI/3))/5;
	
	Baxter_left_arm::Position(0+0.7*sin(0.1*compteur), -position-0.5+0.2*d[0], +0, +position+0.4-1.6*d[1], -0, +position-5*d[2], -0);
}




void Baxter_left_arm::IK(float x, float y, float z, float psy, float teta, float phi)
{
	baxter_core_msgs::SolvePositionIK srv;
	sensor_msgs::JointState JointState ;

	geometry_msgs::PoseStamped PoseStamped;

	PoseStamped.pose.position.x = x ;
	PoseStamped.pose.position.y = y ;
	PoseStamped.pose.position.z = z ;

	//c1=cos(psy/2)
	//c2=cos(teta/2)
	//c3=cos(phi/2)

	//s1=sin(psy/2)
	//s2=sin(teta/2)
	//s3=sin(phi/2)

	PoseStamped.pose.orientation.x = (sin(psy/2)*sin(teta/2)*cos(phi/2)) - (cos(psy/2)*cos(teta/2)*sin(phi/2)) ;
	PoseStamped.pose.orientation.y = (sin(psy/2)*cos(teta/2)*cos(phi/2)) - (cos(psy/2)*sin(teta/2)*sin(phi/2)) ;
	PoseStamped.pose.orientation.z = (cos(psy/2)*sin(teta/2)*cos(phi/2)) - (sin(psy/2)*cos(teta/2)*sin(phi/2)) ;
	PoseStamped.pose.orientation.w = (cos(psy/2)*cos(teta/2)*cos(phi/2)) - (sin(psy/2)*sin(teta/2)*sin(phi/2)) ;

	//std::cout<<PoseStamped.pose.orientation.x<<std::endl;
	//std::cout<<PoseStamped.pose.orientation.y<<std::endl;
	//std::cout<<PoseStamped.pose.orientation.z<<std::endl;
	//std::cout<<PoseStamped.pose.orientation.w<<std::endl;

	PoseStamped.header.seq = 0 ;
	PoseStamped.header.stamp.sec = 0 ;
	PoseStamped.header.frame_id = "base" ;

	srv.request.pose_stamp.resize(1);
	srv.request.pose_stamp[0] = PoseStamped;
	srv.request.seed_mode  = srv.request.SEED_AUTO;

	if (client_inverse_kinematics.call(srv)) 
	{	
		//std::cout<<srv.response<<std::endl;
		msg_JointCommand.command = srv.response.joints[0].position;
	}
	else {ROS_ERROR("Failed to call service IK");}
}


void Baxter_left_arm::Position_attente()
{
	IK(0.3,+0.8,0.5,PI,0,0);
}




void Baxter_left_arm::Position_prise()
{
	IK(0.5,+0.2,0.5,PI,0,0);
	msg_attente_prise.data = false ;
}


void Baxter_left_arm::Descente_prise()
{
	IK(0.5,+0.2,0.2,PI,0,0);
}

void Baxter_left_arm::Prise()
{
	Grip();
}

void Baxter_left_arm::Prise_effectuee()
{
	msg_prise_effectuee.data = true ;
}

void Baxter_left_arm::Position_pose()
{
	IK(0.1,+0.9,0.5,PI,0,0);
}


void Baxter_left_arm::Descente_pose()
{
	msg_prise_effectuee.data = false ;
	IK(0.1,+0.9,0.2,PI,0,0);
}

void Baxter_left_arm::Pose()
{
	Release();
}


void Baxter_left_arm::Attente_prise()
{
	msg_attente_prise.data = true ;
}




bool Baxter_left_arm::Position(float x, float y, float z)
{
	std::vector<bool> position(3,0);
	bool test=1;
	int j=0;

	position[0] = (fabs(endpointState.pose.position.x) - fabs(x)) < (0.05*fabs(x)) ;
	position[1] = (fabs(endpointState.pose.position.y) - fabs(y)) < (0.05*fabs(y)) ;
	position[2] = (fabs(endpointState.pose.position.z) - fabs(z)) < (0.05*fabs(z)) ;

	//std::cout<< fabs(endpointState.pose.position.x) <<" <<    --    >> "<< fabs(x) <<std::endl;
	//std::cout<< fabs(endpointState.pose.position.y) <<" <<    --    >> "<< fabs(y) <<std::endl;
	//std::cout<< fabs(endpointState.pose.position.z) <<" <<    --    >> "<< fabs(z) <<std::endl;

	while(j<3) 
	{
		test*=position[j];
		j++;
		//std::cout<<"test	"<<test<<" --- >"<<position[j-1]<<std::endl;
	}

	return test;
}

bool Baxter_left_arm::Prise_demmandee()
{
	if (msg_prise_demandee.data == true) 
	{
		msg_prise_demandee.data = false ;
		return true ;
	}
	else return false ;
}

bool Baxter_left_arm::Position_prise_OK()
{
	return Position(0.5,+0.2,0.5);
}

bool Baxter_left_arm::Descente_prise_OK()
{
	return Position(0.5,+0.2,0.2);
}

bool Baxter_left_arm::Position_pose_OK()
{
	return Position(0.1,+0.9,0.5);
}

bool Baxter_left_arm::Descente_pose_OK()
{
	return Position(0.1,+0.9,0.2);
}



bool Baxter_left_arm::Pince_fermee()
{
	return endEffectorState.gripping ;
}

bool Baxter_left_arm::Pince_fermee_pos()
{
	return endEffectorState.position < 50 ;
}

bool Baxter_left_arm::Pince_ouverte()
{
	return endEffectorState.position > 90 ;
}



bool Baxter_left_arm::vitesse_nulle()
{
	std::vector<bool> vitesse(17,0);
	bool test=1;
	int j=0;

	for(size_t i = 0; i < 17; i++) 
	{
		vitesse[i] = jointState.velocity[i] < 0.03 ;
		//std::cout<<vitesse[i]<<std::endl;
	}

	while(j<17) 
	{
		test*=vitesse[j];
		j++;
		//std::cout<<"test"<<test<<std::endl;
	}

	return test;
}















