
#include <iostream>
#include <vector>

class Iskrovik;
class Ñompass;
class Flame;

//Abstract visitor
class ArtifactRestorer {
public:
	virtual void restore(Iskrovik* iskrovik) = 0;
	virtual void restore(Ñompass* compass) = 0;
	virtual void restore(Flame* flame) = 0;
};

//Abstract element
class Artifact {
public:
	void change_state(float x) {
		state += x;
		if (state > 1.0) state = 1.0;
		if (state < 0.0) state = 0.0;
	}
	virtual void accept(ArtifactRestorer* art_restorer) = 0;
	void check_state() {
		std::cout << state << std::endl;
	}
protected:
	float state = 0.0;
};

//Concrete elements
class Iskrovik : public Artifact {
public:
	void accept(ArtifactRestorer* art_restorer) override {
		art_restorer->restore(this);
	}
};
class Ñompass : public Artifact {
public:
	void accept(ArtifactRestorer* art_restorer) override {
		art_restorer->restore(this);
	}
};
class Flame : public Artifact {
public:
	void accept(ArtifactRestorer* art_restorer) override {
		art_restorer->restore(this);
	}
};


//Concrete visitors
class StrongArtifactRestorer : public ArtifactRestorer {
public:
	void restore(Iskrovik* iskrovik) override {
		iskrovik->change_state(0.9);
	}
	void restore(Ñompass* compass) override {
		compass->change_state(0.8);
	}
	void restore(Flame* flame) override {
		flame->change_state(0.6);
	}
};

class WeakArtifactRestorer : public ArtifactRestorer {
public:
	void restore(Iskrovik* iskrovik) override {
		iskrovik->change_state(0.4);
	}
	void restore(Ñompass* compass) override {
		compass->change_state(0.2);
	}
	void restore(Flame* flame) override {
		flame->change_state(0.1);
	}
};

//Structure with elements
class ArtifactContainer {
public:
	std::vector<Artifact*> artifacts;
};

//int main() {
//	ArtifactContainer art_cont;
//	art_cont.artifacts.push_back(new Iskrovik);
//	art_cont.artifacts.push_back(new Iskrovik);
//	art_cont.artifacts.push_back(new Iskrovik);
//	art_cont.artifacts.push_back(new Flame);
//	art_cont.artifacts.push_back(new Ñompass);
//	WeakArtifactRestorer restorer;
//	for (auto& artifact : art_cont.artifacts) {
//		artifact->accept(&restorer);
//		artifact->check_state();
//	}
//	StrongArtifactRestorer s_restorer;
//	for (auto& artifact : art_cont.artifacts) {
//		artifact->accept(&s_restorer);
//		artifact->check_state();
//	}
//}