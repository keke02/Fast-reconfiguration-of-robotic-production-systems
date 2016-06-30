/**** Bruno DATO M1 EEA ISTR Université Paul Sabatier Toulouse III 2016 ****/

#include <ros/ros.h>
#include "communication_baxter.h"
#include "std_msgs/Bool.h"
#include "commande_baxter/bool_state.h"

#define RESET   "\033[0m"
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */

// Constructeur
Communication_Baxter::Communication_Baxter(ros::NodeHandle noeud)
{
	// Publisher

	pub_prise_demandee_bras_droit = noeud.advertise<std_msgs::Bool>("/pont_BaxterLigneTransitique/right_arm/prise_demandee", 1);
	pub_prise_demandee_bras_gauche = noeud.advertise<std_msgs::Bool>("/pont_BaxterLigneTransitique/left_arm/prise_demandee", 1);
	
	// Subscriber

	sub_prise_effectuee_bras_droit = noeud.subscribe("/pont_BaxterLigneTransitique/right_arm/prise_effectuee", 1, &Communication_Baxter::Callback_prise_effectuee_bras_droit,this);
	sub_prise_effectuee_bras_gauche = noeud.subscribe("/pont_BaxterLigneTransitique/left_arm/prise_effectuee", 1, &Communication_Baxter::Callback_prise_effectuee_bras_gauche,this);
	sub_attente_prise_bras_droit = noeud.subscribe("/pont_BaxterLigneTransitique/right_arm/attente_prise", 1, &Communication_Baxter::Callback_attente_prise_bras_droit,this);
	sub_attente_prise_bras_gauche = noeud.subscribe("/pont_BaxterLigneTransitique/left_arm/attente_prise", 1, &Communication_Baxter::Callback_attente_prise_bras_gauche,this);


	//Client
	client_prise_effectuee_bras_gauche = noeud.serviceClient<commande_baxter::bool_state>("/pont_BaxterLigneTransitique/service/left_arm/prise_effectuee",true);
	client_attente_prise_bras_gauche = noeud.serviceClient<commande_baxter::bool_state>("/pont_BaxterLigneTransitique/service/left_arm/attente_prise",true);

	//Server
	srv_prise_demandee_bras_gauche = noeud.advertiseService("/pont_BaxterLigneTransitique/service/left_arm/prise_demandee", &Communication_Baxter::Srv_prise_demandee_bras_gauche,this);

	msg_prise_demandee_bras_droit.data = false ;
	msg_prise_effectuee_bras_droit.data = false ;

	msg_prise_demandee_bras_gauche.data = false ;
	msg_prise_effectuee_bras_gauche.data = false ;

	msg_attente_prise_bras_gauche.data = false ;
	msg_attente_prise_bras_gauche.data = false ;


}


// Destructeur
Communication_Baxter::~Communication_Baxter()
{
}

// Callbacks
void Communication_Baxter::Callback_prise_effectuee_bras_droit(const std_msgs::Bool& msg)
{
	msg_prise_effectuee_bras_droit = msg ;
	if (msg_prise_effectuee_bras_droit.data == 1) msg_prise_demandee_bras_droit.data = false;
	//std::cout<<msg<<std::endl;
}

void Communication_Baxter::Callback_prise_effectuee_bras_gauche(const std_msgs::Bool& msg)
{
	msg_prise_effectuee_bras_gauche = msg ;
	if (msg_prise_effectuee_bras_gauche.data == 1) msg_prise_demandee_bras_gauche.data = false;
	//std::cout<<msg<<std::endl;
}

void Communication_Baxter::Callback_attente_prise_bras_gauche(const std_msgs::Bool& msg)
{
	msg_attente_prise_bras_gauche = msg ;
	//std::cout<<msg<<std::endl;
}

void Communication_Baxter::Callback_attente_prise_bras_droit(const std_msgs::Bool& msg)
{
	msg_attente_prise_bras_droit = msg ;
	//std::cout<<msg<<std::endl;
}



//Service
bool Communication_Baxter::Srv_prise_demandee_bras_gauche(commande_baxter::bool_state::Request  &req,
         commande_baxter::bool_state::Response &res)
{
  res.state = msg_prise_demandee_bras_gauche.data * req.query;
  return true;
}







bool Communication_Baxter::Prise_effectuee_bras_droit()
{
	if( msg_prise_effectuee_bras_droit.data == true )
	{
		msg_prise_effectuee_bras_droit.data = false ;
		msg_prise_demandee_bras_droit.data = false ;
		return true;
	}
	else return false ;
}

bool Communication_Baxter::Prise_effectuee_bras_gauche()
{
	commande_baxter::bool_state srv;
	bool query = true;

	srv.request.query = query;
	
	if (client_prise_effectuee_bras_gauche.call(srv)) 
	{	
		//std::cout<<srv.response<<std::endl;
		msg_prise_effectuee_bras_gauche.data = srv.response.state;
	}
	else {ROS_ERROR("Failed to call service Prise_effectuee_bras_gauche()");}


	if( msg_prise_effectuee_bras_gauche.data == true )
	{
		msg_prise_effectuee_bras_gauche.data = false ;
		msg_prise_demandee_bras_gauche.data = false ;
		return true;
	}
	else return false ;
}

bool Communication_Baxter::Attente_prise_bras_droit()
{
	if( msg_attente_prise_bras_droit.data == true )
	{
		//msg_attente_prise_bras_droit.data = false ;
		return true;
	}
	else return false ;
}

bool Communication_Baxter::Attente_prise_bras_gauche()
{
	commande_baxter::bool_state srv;
	bool query = true ;	std::cout<<"1"<<std::endl;
	
	srv.request.query = query;	std::cout<<"2"<<std::endl;
	
	//std::cout<<client_attente_prise_bras_gauche.call(srv)<<std::endl;

	//std::cout<<srv.response<<std::endl;

	if (client_attente_prise_bras_gauche.call(srv)) 
	{	
			
		std::cout<<srv.response<<std::endl;
		msg_attente_prise_bras_gauche.data = srv.response.state; 
	}
	else {ROS_ERROR("Failed to call service Attente_prise_bras_gauche()");}

		std::cout<<"4"<<std::endl;

	if( msg_attente_prise_bras_gauche.data == true )
	{
		//msg_attente_prise_bras_gauche.data = false ; 	std::cout<<"5"<<std::endl;
		return true;
	}
	else return false ;
}

void Communication_Baxter::Demander_prise_bras_droit()
{
	msg_prise_demandee_bras_droit.data = true ;
	msg_attente_prise_bras_droit.data = false ;
}

void Communication_Baxter::Demander_prise_bras_gauche()
{
	msg_prise_demandee_bras_gauche.data = true ;
	msg_attente_prise_bras_gauche.data = false ;
}
	

void Communication_Baxter::Update()
{
	pub_prise_demandee_bras_droit.publish(msg_prise_demandee_bras_droit);
	pub_prise_demandee_bras_gauche.publish(msg_prise_demandee_bras_gauche);
}



//Affichage

void Communication_Baxter::Afficher_Communication_Baxter()
{
	std::cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
	std::cout <<"~~~~~~~~~~~~~ "<< BOLDYELLOW <<"Communication BAXTER"<< RESET <<" ~~~~~~~~~~~~~~"<<std::endl;
	std::cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl<<std::endl;

	std::cout << std::endl<<std::endl;

	std::cout <<"~~~~~~~~~~~~~~~~~~ "<< BOLDYELLOW <<"Bras Droit"<< RESET <<" ~~~~~~~~~~~~~~~~~~~"<<std::endl<<std::endl;

	
	if (msg_attente_prise_bras_droit.data == 1) std::cout << BOLDGREEN << "attente prise" << RESET <<"     ";
	else std::cout << BOLDRED << "attente prise" << RESET <<"     ";

	if (msg_prise_demandee_bras_droit.data == 1) std::cout << BOLDGREEN << "prise demandée" << RESET <<"     ";
	else std::cout << BOLDRED << "prise demandée" << RESET <<"     ";

	if (msg_prise_effectuee_bras_droit.data == 1) std::cout << BOLDGREEN << "prise effectuée" << RESET <<"     ";
	else std::cout << BOLDRED << "prise effectuée" << RESET <<"     ";

	std::cout << std::endl<<std::endl;

	std::cout <<"~~~~~~~~~~~~~~~~~~ "<< BOLDYELLOW <<"Bras Gauche"<< RESET <<" ~~~~~~~~~~~~~~~~~~"<<std::endl<<std::endl;

	
	if (msg_attente_prise_bras_gauche.data == 1) std::cout << BOLDGREEN << "attente prise" << RESET <<"     ";
	else std::cout << BOLDRED << "attente prise" << RESET <<"     ";

	if (msg_prise_demandee_bras_gauche.data == 1) std::cout << BOLDGREEN << "prise demandée" << RESET <<"     ";
	else std::cout << BOLDRED << "prise demandée" << RESET <<"     ";

	if (msg_prise_effectuee_bras_gauche.data == 1) std::cout << BOLDGREEN << "prise effectuée" << RESET <<"     ";
	else std::cout << BOLDRED << "prise effectuée" << RESET <<"     ";

	std::cout << std::endl<<std::endl;
	std::cout << std::endl<<std::endl;
}



