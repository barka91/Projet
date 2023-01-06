#include "Domino/DomEngine.hpp"
// faire en sorte que les imput ne marche plus lorsque le game est OVER  

void DomEngine::input()
{
    //Event polling
	while (this->window->pollEvent(this->ev))
    {
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;

		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		
		case sf::Event::MouseButtonPressed:
			if (currentGameState==GameState::GAMEOVER){
				if(this->ev.mouseButton.button == sf::Mouse::Left) this->window->close();	
			}		
				
			if (this->ev.mouseButton.button == sf::Mouse::Left){

				
				Vector2f mouse = window->mapPixelToCoords(Mouse::getPosition(*window));
				
				if( button1.getGlobalBounds().contains(mouse)){
					sac.at(0)->tourner();
				}

				if( button2.getGlobalBounds().contains(mouse)){
					defausser();
				}

				for (size_t i = 0; i < tabEmplacement.size(); i++) {
					DomEmplacement* e = tabEmplacement.at(i);
					FloatRect bounds=e->getShape().getGlobalBounds();
					if (bounds.contains(mouse)){
						if (isBonnePlace(e,sac.at(0))){
							// on place la DomTuile a la place choisi
							sac.at(0)->setPosition(e->getShape().getPosition());
							plateau.push_back(sac.at(0));
							tabEmplacement.erase(tabEmplacement.begin() + i);
							
							// on place les nouveaux emplacements vides 
							initVoisin(sac.at(0));
							sac.erase(sac.begin());
			
							// on attibue les points au joueur et on change de joueur 
							joueurSuivant(e->getPoints());
						}
						break;	
					}
				}
			}
		}
	}
}