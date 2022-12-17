#include "DomEngine.hpp"

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
			

			if (this->ev.key.code == sf::Keyboard::Space){
				sac.at(0)->tourner();
			}

			if (this->ev.key.code == sf::Keyboard::P){
				defausser();

			}

			break;
		
		case sf::Event::MouseButtonPressed:
			if (this->ev.mouseButton.button == sf::Mouse::Left){
				Vector2f mouse = window->mapPixelToCoords(Mouse::getPosition(*window));
				for (size_t i = 0; i < tabEmplacement.size(); i++) {
					EmplacementVide* e = tabEmplacement.at(i);
					FloatRect bounds=e->getShape().getGlobalBounds();
					if (bounds.contains(mouse)){
						// si verification ok:
						if (isBonnePlace(e,sac.at(0))){
							// on place la tuile a la place choisi
							cout<<"oue c'est la bonne place mon reuf gg"<<endl;
							sac.at(0)->setPosition(e->getShape().getPosition());
							plateau.push_back(sac.at(0));
							tabEmplacement.erase(tabEmplacement.begin() + i);
							// on place les nouveaux emplacements vides 
							racks(sac.at(0));
							sac.erase(sac.begin());
							// on change de joueur 
							joueurSuivant();
						}
						else
						{
							cout<<"t'es bete ou quoi "<<endl;
							
						}
						break;
						
					}
				}

				// on place les nouveaux emplacements vides 
				// racks(sac.at(0));
				
				
				// sac.erase(sac.begin());
			
		 
			}

			if (this->ev.mouseButton.button == sf::Mouse::Right){
				Vector2f mouse = window->mapPixelToCoords(Mouse::getPosition(*window));
				for (size_t i = 0; i < tabEmplacement.size(); i++) {
					EmplacementVide* e = tabEmplacement.at(i);
					FloatRect bounds=e->getShape().getGlobalBounds();
					if (bounds.contains(mouse)){
						cout<<*e<<endl;
						break;
					}

				}
			}
		}
	}
}