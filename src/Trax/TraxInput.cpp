#include "Trax/TraxEngine.hpp"  

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
			if (currentGameState==GameState::GAMEOVER){
				if(this->ev.mouseButton.button == sf::Mouse::Left) this->window->close();	
			}

			if (this->ev.mouseButton.button == sf::Mouse::Left){
				Vector2f mouse = window->mapPixelToCoords(Mouse::getPosition(*window));

 				if( button1.getGlobalBounds().contains(mouse)){
					tourne();
					
				}

				if( button2.getGlobalBounds().contains(mouse)){
					change();
				}

				if (coordCF.first != -1 && coordCF.second != -1)
				{
					TraxEmplacement* e = tabTraxEmplacement.at(coordCF.first).at(coordCF.second);
					FloatRect bounds=e->getShape().getGlobalBounds();
					if (bounds.contains(mouse)){
						placement(e);
						break;
					}
				}
				else{
					for (int i = 0; i < 8; i++){
						for (int j = 0; j < 8; j++) {
							TraxEmplacement* e = tabTraxEmplacement.at(i).at(j);
							FloatRect bounds=e->getShape().getGlobalBounds();
							if (bounds.contains(mouse)){
								placement(e);
								break;
							}
						}	
					}	
				}
			}		 
		}
	}
}
