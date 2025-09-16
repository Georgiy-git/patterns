
#include <map>
#include <iostream>

enum class TextureEnum {
	tree,
	stone,
	cloud
};
using enum TextureEnum;

class Texture {
public:
	Texture(TextureEnum texture) : texture(texture) {
		std::cout << "texture is created\n";
	}
	void draw(int x, int y) {}

private:
	TextureEnum texture;
};

class TextureFactory {
public:
	Texture* get_texture(TextureEnum _texture) {
		if (textures.find(_texture) == textures.end()) {
			textures[_texture] = new Texture{ _texture };
		}
		return textures[_texture];
	}
private:
	std::map<TextureEnum, Texture*> textures;
};

//int main() {
//	TextureFactory factory;
//	auto t1 = factory.get_texture(tree);
//	auto t2 = factory.get_texture(tree);
//	auto t3 = factory.get_texture(cloud);
//	auto t4 = factory.get_texture(stone);
//	auto t5 = factory.get_texture(tree);
//	t1->draw(100, 20);
//}