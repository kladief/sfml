#include "Animation.h"

void Animation::createRectBuffer(){
	sf::Vector2 txRnC = {std::trunc(img.getSize().x/txSize.x)
							         ,std::trunc(img.getSize().y/txSize.y)};
	rectBuffer.resize(txRnC.x*txRnC.y);
	for(int y=0;y<txRnC.y;y++){
		for(int x=0;x<txRnC.x;x++){
			rectBuffer[x+y*txRnC.x]={int(txSize.x*x),
												int(txSize.y*y),
												int(txSize.x),
												int(txSize.y)};
		}
	}
}
int Animation::nextFrame(){
	if(frame>fps*frames-1)
		frame=0;
	_sprite->setTextureRect(rectBuffer[std::trunc(frame/fps)]);
	frame++;
	return 0;
}