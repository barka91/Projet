#include "Trax/TraxEngine.hpp"
// faire en sorte que les imput ne marche plus lorsque le game est OVER  

void TraxEngine::input()
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
			if (this->ev.mouseButton.button == sf::Mouse::Left){
				Vector2f mouse = window->mapPixelToCoords(Mouse::getPosition(*window));

 				if( button1.getGlobalBounds().contains(mouse)){
					TraxTuileSelected->tourner();
					
				}

				if( button2.getGlobalBounds().contains(mouse)){
					change();
					
				}

				for (int i = 0; i < 8; i++){
					for (int j = 0; j < 8; j++) {
						Emplacement* e = tabEmplacement.at(i).at(j);
						FloatRect bounds=e->getShape().getGlobalBounds();
						if (bounds.contains(mouse)){
							cout<<"yooooooooooo la kdjkjd"<<endl;
							// tutu.push_back( new TraxTuileDroit(sf::Vector2f(e->getShape().getPosition())) );
							TraxTuileSelected->setPosition(e->getShape().getPosition());
							tutu.push_back(TraxTuileSelected );
							TraxTuileSelected = new TraxTuileCourbe(sf::Vector2f(100,100));
							// placer la tuile jsp si je fais un fonction qui place ou jutilise une methode qui change non je vais utiliser les deux 
							break;
						}
						
					}
				
					
				}

				// on place les nouveaux emplacements vides 
				// racks(sac.at(0));
				
				
				// sac.erase(sac.begin());
			
		 
			}

		


		
		}
	}
}