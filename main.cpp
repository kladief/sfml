#include "SfmlHeaders.h"
#include "Animation.h"
#include <vector>
#include <fstream>

std::ofstream file("log.info");

int main(){
	using namespace std;
	using namespace sf;
	RenderWindow window(VideoMode(640,480),"Example");
	window.setFramerateLimit(30);
	sf::Sprite sprite;
	sf:Text text;
	sf::Font font;
	sf::Clock clock;
	Animation run(&sprite,
			"/home/artem/c++/sfml/exemple1/Asset Packs 1-3 (final)/Asset Pack-V1/Sprite Sheets/run cycle 48x48.png",
			{48,48},
			5);
	
	if(!run.isCreate())
		return 0;
	
	sprite.setPosition({10,10});
	sprite.setScale({5,5});
	bool fontLoad=font.loadFromFile("/home/artem/.cache/yay/electron17/src/src/third_party/angle/src/libANGLE/overlay/DejaVuSansMono-Bold.ttf");
	if(!fontLoad)
		return 0;

	text.setFont(font);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::White);
	while(window.isOpen()){
		Event event;
		while(window.pollEvent(event)){
			if(event.type==Event::Closed){
				window.close();
			}
		}
		float fps=1/clock.getElapsedTime().asSeconds();
		text.setString("fps:"+std::to_string(fps));
		clock.restart();
		window.clear();
		run.nextFrame();
		window.draw(sprite);
		window.draw(text);
		window.display();
	}
	file.close();
	return 0;
}
