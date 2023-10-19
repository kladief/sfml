#include "SfmlHeaders.h"
#include <vector>
#include <cmath>


class Animation{
	sf::Image img;
	sf::Texture tx;
	sf::Sprite* _sprite;
	std::vector< sf::IntRect > rectBuffer;
	sf::Vector2u txSize;
	int fps;
	int frames;
	int frame;
	void createRectBuffer();
	
public:
	Animation(sf::Sprite* sprite,const std::string& fileDirName,sf::Vector2u rect,int frame=1): _sprite(sprite),fps(frame),txSize(rect),frame(1){
	if(!img.loadFromFile(fileDirName))
			return;
		if(!tx.loadFromImage(img))
			return;
		frames=std::trunc(img.getSize().x/rect.x)
					*std::trunc(img.getSize().y/rect.y);
		createRectBuffer();
		_sprite->setTexture(tx);
		_sprite->setTextureRect(rectBuffer[0]);
	}
	sf::Vector2u getTxSize(){
		return txSize;
	}
	void start(){
		_sprite->setTexture(tx);
		_sprite->setTextureRect(rectBuffer[0]);
		frame=1;
	}
	bool isCreate(){
		return frames ? 1:0;
	}
	int nextFrame();
};