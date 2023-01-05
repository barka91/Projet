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
			Vector2f mouse = window->mapPixelToCoords(Mouse::getPosition(*window));
			if(this->ev.mouseButton.button == sf::Mouse::Right){
				for (int i = 0; i < 8; i++){
					for (int j = 0; j < 8; j++) {
						TraxEmplacement* e = tabTraxEmplacement.at(i).at(j);
						FloatRect bounds=e->getShape().getGlobalBounds();
						if (bounds.contains(mouse)){
							info(e);
						}
					}
				}

			}

			if (this->ev.mouseButton.button == sf::Mouse::Left){
				cout<<coordCF.first<<coordCF.second<<endl;
				Vector2f mouse = window->mapPixelToCoords(Mouse::getPosition(*window));

 				if( button1.getGlobalBounds().contains(mouse)){
					tourne();
					
				}

				if( button2.getGlobalBounds().contains(mouse)){
					change();
					
				}

				// a revoir 
				int i,j;
				if (coordCF.first != -1 && coordCF.second != -1)
				{
					i = coordCF.first;
					j = coordCF.second;
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
				


				// on place les nouveaux emplacements vides 
				// racks(sac.at(0));
				
				
				// sac.erase(sac.begin());
			
		 
			}

		


		
		}
	}
