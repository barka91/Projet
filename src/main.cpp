// #include <iostream>
// #include "Domino/DomEngine.hpp"
// #include "Trax/TraxEngine.hpp"

// //using namespace sf;

// int main()
// {
// 	// Création de la fenêtre de jeu
//     sf::RenderWindow window(sf::VideoMode(800, 600), "MENU");

// 	// Chargement de la police d'écriture
//     sf::Font font;
//     if (!font.loadFromFile("assets/fonts/roboto.ttf"))
//         return 1;

// 	// Création du bouton du jeu domino
// 	sf::RectangleShape button1(sf::Vector2f(250, 50));
// 	button1.setPosition(200, 300);
// 	button1.setFillColor(sf::Color::Green);

// 	sf::Text buttonText1;
// 	buttonText1.setString("Dominos carrees");
// 	buttonText1.setFont(font);
// 	buttonText1.setCharacterSize(24);
// 	buttonText1.setFillColor(sf::Color::White);

// 	// Centrer le texte dans le bouton
// 	sf::FloatRect textRect1 = buttonText1.getLocalBounds();
// 	buttonText1.setOrigin(textRect1.left + textRect1.width / 2.0f,
// 						textRect1.top + textRect1.height / 2.0f);
// 	buttonText1.setPosition(sf::Vector2f(button1.getPosition().x + button1.getSize().x / 2.0f, 
// 							button1.getPosition().y + button1.getSize().y / 2.0f));

// 	// Création du bouton du jeu trax
// 	sf::RectangleShape button2(sf::Vector2f(250, 50));
// 	button2.setPosition(200, 240);
// 	button2.setFillColor(sf::Color::Red);

// 	sf::Text buttonText2;
// 	buttonText2.setString("Trax");
// 	buttonText2.setFont(font);
// 	buttonText2.setCharacterSize(24);
// 	buttonText2.setFillColor(sf::Color::White);

// 	// Centrer le texte dans le bouton
// 	sf::FloatRect textRect2 = buttonText2.getLocalBounds();
// 	buttonText2.setOrigin(textRect2.left + textRect2.width / 2.0f,
// 						textRect2.top + textRect2.height / 2.0f);
// 	buttonText2.setPosition(sf::Vector2f(button2.getPosition().x + button2.getSize().x / 2.0f, 
// 							button2.getPosition().y + button2.getSize().y / 2.0f));

// 	// Création du bouton du jeu Carcasonne
// 	sf::RectangleShape button3(sf::Vector2f(250, 50));
// 	button3.setPosition(200, 360);
// 	button3.setFillColor(sf::Color::Blue);

// 	sf::Text buttonText3;
// 	buttonText3.setString("Carcasonne");
// 	buttonText3.setFont(font);
// 	buttonText3.setCharacterSize(24);
// 	buttonText3.setFillColor(sf::Color::White);

// 	// Centrer le texte dans le bouton
// 	sf::FloatRect textRect3 = buttonText3.getLocalBounds();
// 	buttonText3.setOrigin(textRect3.left + textRect3.width / 2.0f,
// 						textRect3.top + textRect3.height / 2.0f);
// 	buttonText3.setPosition(sf::Vector2f(button3.getPosition().x + button3.getSize().x / 2.0f, 
// 							button3.getPosition().y + button3.getSize().y / 2.0f));

//     // Création du texte pour le titre du jeu
//     sf::Text title;
//     title.setFont(font);
//     title.setString("Mon jeu");
//     title.setCharacterSize(64);
//     title.setFillColor(sf::Color::White);
//     title.setStyle(sf::Text::Bold);
//     title.setPosition(sf::Vector2f(320, 50));

//     // Boucle principale du jeu
//     while (window.isOpen())
//     {
//         // Gestion des événements
//         sf::Event event;
//         while (window.pollEvent(event))
//         {
//             if (event.type == sf::Event::Closed)
//                 window.close();

// 			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
// 			{
// 				Vector2f mouse = window.mapPixelToCoords(Mouse::getPosition(window));
// 				if( button1.getGlobalBounds().contains(mouse))
// 				{
// 					// Init Game engine
// 					DomEngine domEngine{2};
// 					//Game loop
// 					domEngine.run();
// 				}

// 				if( button2.getGlobalBounds().contains(mouse))
// 				{
// 					// Init Game engine
// 					TraxEngine TraxEngine{};
// 					//Game loop
// 					TraxEngine.run();
// 					//End of application
					
// 				}

// 				if( button3.getGlobalBounds().contains(mouse))
// 				{
// 					cout<<"Carcasonne en construction"<<endl;
// 				}
				
// 			}
//         }

//         // Affichage de la page d'accueil
//         window.clear();
//         window.draw(button1);
//         window.draw(buttonText1);
// 		window.draw(button2);
//         window.draw(buttonText2);
// 		window.draw(button3);
//         window.draw(buttonText3);
//         window.draw(title);
//         window.display();
//     }

	

// 	//End of application
// 	return 0;
// }


#include <iostream>
#include "Domino/DomEngine.hpp"
#include "Trax/TraxEngine.hpp"

//using namespace sf;

int main()
{
	//Init srand
	std::srand(static_cast<unsigned>(time(NULL)));

	// Init Game engine
	TraxEngine TraxEngine{};
	//Game loop
	TraxEngine.run();
	//End of application
	return 0;

	// -----------------------------------------------

	// //Init srand
	// std::srand(static_cast<unsigned>(time(NULL)));

	// // Init Game engine
	// DomEngine DomEngine{2};
	// //Game loop
	// DomEngine.run();
	// //End of application
	// return 0;

	
}