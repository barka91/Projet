#include <iostream>
#include "Domino/DomEngine.hpp"
#include "Trax/TraxEngine.hpp"

//using namespace sf;

int main()
{
	// Création de la fenêtre de jeu
    sf::RenderWindow window(sf::VideoMode(800, 600), "MENU");

	// Chargement de la police d'écriture
    sf::Font font;
    if (!font.loadFromFile("assets/fonts/roboto.ttf"))
        return 1;

	// Création du bouton du jeu domino
	sf::RectangleShape button1(sf::Vector2f(250, 50));
	button1.setPosition(150, 300);
	button1.setFillColor(sf::Color(255, 192, 203));

	sf::Text buttonText1;
	buttonText1.setString("Dominos carrees");
	buttonText1.setFont(font);
	buttonText1.setCharacterSize(24);
	buttonText1.setFillColor(sf::Color::White);

	// Centrer le texte dans le bouton
	sf::FloatRect textRect1 = buttonText1.getLocalBounds();
	buttonText1.setOrigin(textRect1.left + textRect1.width / 2.0f,
						textRect1.top + textRect1.height / 2.0f);
	buttonText1.setPosition(sf::Vector2f(button1.getPosition().x + button1.getSize().x / 2.0f, 
							button1.getPosition().y + button1.getSize().y / 2.0f));

	// Création du bouton du jeu trax
	sf::RectangleShape button2(sf::Vector2f(250, 50));
	button2.setPosition(150, 240);
	button2.setFillColor(sf::Color(238, 130, 238));

	sf::Text buttonText2;
	buttonText2.setString("Trax");
	buttonText2.setFont(font);
	buttonText2.setCharacterSize(24);
	buttonText2.setFillColor(sf::Color::White);

	// Centrer le texte dans le bouton
	sf::FloatRect textRect2 = buttonText2.getLocalBounds();
	buttonText2.setOrigin(textRect2.left + textRect2.width / 2.0f,
						textRect2.top + textRect2.height / 2.0f);
	buttonText2.setPosition(sf::Vector2f(button2.getPosition().x + button2.getSize().x / 2.0f, 
							button2.getPosition().y + button2.getSize().y / 2.0f));

	// Création du bouton du jeu Carcasonne
	sf::RectangleShape button3(sf::Vector2f(250, 50));
	button3.setPosition(150, 360);
	button3.setFillColor(sf::Color(64, 224, 208));

	sf::Text buttonText3;
	buttonText3.setString("Carcasonne");
	buttonText3.setFont(font);
	buttonText3.setCharacterSize(24);
	buttonText3.setFillColor(sf::Color::White);

	// Centrer le texte dans le bouton
	sf::FloatRect textRect3 = buttonText3.getLocalBounds();
	buttonText3.setOrigin(textRect3.left + textRect3.width / 2.0f,
						textRect3.top + textRect3.height / 2.0f);
	buttonText3.setPosition(sf::Vector2f(button3.getPosition().x + button3.getSize().x / 2.0f, 
							button3.getPosition().y + button3.getSize().y / 2.0f));

    // Création du texte pour le titre du jeu
    sf::Text title;
    title.setFont(font);
    title.setString("Mon jeu");
    title.setCharacterSize(64);
    title.setFillColor(sf::Color::White);
    title.setStyle(sf::Text::Bold);
    title.setPosition(sf::Vector2f(320, 50));

	// Initialisation du nombre à 2
    int number = 2;

    // Création du texte pour afficher le nombre
    sf::Text numberText;
	numberText.setFont(font);
    numberText.setCharacterSize(35);
    numberText.setString("Nombre de joueur: "+to_string(number));
    numberText.setFillColor(sf::Color::White);
	sf::FloatRect textRect = numberText.getLocalBounds();
	numberText.setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
	numberText.setPosition(sf::Vector2f(600, 325));

    // Création du bouton pour incrémenter le nombre
    sf::RectangleShape incrementButton(sf::Vector2f(100, 50));
    incrementButton.setFillColor(sf::Color::Green);
	incrementButton.setPosition(550, 325 - incrementButton.getSize().y - 30);

	sf::Text incrText;
	incrText.setString("+");
	incrText.setFont(font);
	incrText.setCharacterSize(24);
	incrText.setFillColor(sf::Color::White);

	// Centrer le texte dans le bouton
	sf::FloatRect incrRect = incrText.getLocalBounds();
	incrText.setOrigin(incrRect.left + incrRect.width / 2.0f,
						incrRect.top + incrRect.height / 2.0f);
	incrText.setPosition(sf::Vector2f(incrementButton.getPosition().x + incrementButton.getSize().x / 2.0f, 
							incrementButton.getPosition().y + incrementButton.getSize().y / 2.0f));
    
	// Création du bouton pour décrémenter le nombre
    sf::RectangleShape decrementButton(sf::Vector2f(100, 50));
    decrementButton.setFillColor(sf::Color::Red);
	decrementButton.setPosition(550, 325 + 30);

	sf::Text decrText;
	decrText.setString("-");
	decrText.setFont(font);
	decrText.setCharacterSize(24);
	decrText.setFillColor(sf::Color::White);

	// Centrer le texte dans le bouton
	sf::FloatRect decrRect = decrText.getLocalBounds();
	decrText.setOrigin(decrRect.left + decrRect.width / 2.0f,
						decrRect.top + decrRect.height / 2.0f);
	decrText.setPosition(sf::Vector2f(decrementButton.getPosition().x + decrementButton.getSize().x / 2.0f, 
							decrementButton.getPosition().y + decrementButton.getSize().y / 2.0f));



    // Boucle principale du jeu
    while (window.isOpen())
    {
        // Gestion des événements
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				Vector2f mouse = window.mapPixelToCoords(Mouse::getPosition(window));
				if( button1.getGlobalBounds().contains(mouse))
				{
					// Init Game engine
					DomEngine domEngine{number};
					//Game loop
					domEngine.run();
				}

				if( button2.getGlobalBounds().contains(mouse))
				{
					// Init Game engine
					TraxEngine TraxEngine{};
					//Game loop
					TraxEngine.run();
					//End of application
					
				}

				if( button3.getGlobalBounds().contains(mouse))
				{
					cout<<"Carcasonne en construction"<<endl;
				}

				// Incrémentation du nombre lorsque le bouton est cliqué           
                if (incrementButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                {
                    if (number < 5)
                    {
                        number++;
                        numberText.setString("Nombre de joueur: "+to_string(number));
                    }
                }

                // Décrémentation du nombre lorsque le bouton est cliqué
                if (decrementButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                {
                    if (number > 2)
                    {
                        number--;
                        numberText.setString("Nombre de joueur: "+to_string(number));
                    }
                }
           
				
			}
        }

        // Affichage de la page d'accueil
        window.clear();

        window.draw(button1);
        window.draw(buttonText1);
		window.draw(button2);
        window.draw(buttonText2);
		window.draw(button3);
        window.draw(buttonText3);
        window.draw(title);
		window.draw(numberText);
        window.draw(incrementButton);
        window.draw(decrementButton);
		window.draw(incrText);
        window.draw(decrText);

        window.display();
    }

	

	//End of application
	return 0;
}














// #include <iostream>
// #include "Domino/DomEngine.hpp"
// #include "Trax/TraxEngine.hpp"

// //using namespace sf;

// int main()
// {
// 	//Init srand
// 	std::srand(static_cast<unsigned>(time(NULL)));

// 	// Init Game engine
// 	TraxEngine TraxEngine{};
// 	//Game loop
// 	TraxEngine.run();
// 	//End of application
// 	return 0;

// 	// -----------------------------------------------

// 	// //Init srand
// 	// std::srand(static_cast<unsigned>(time(NULL)));

// 	// // Init Game engine
// 	// DomEngine DomEngine{2};
// 	// //Game loop
// 	// DomEngine.run();
// 	// //End of application
// 	// return 0;

	
// }