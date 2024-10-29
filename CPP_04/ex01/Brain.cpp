#include "Brain.Class.hpp"

Brain::Brain()
{
	std::string Ideas;
	std::string NumOfIdeas;

	for (int i = 0; i < 100; i++)
	{
		Ideas = "Ideas_";
		NumOfIdeas = std::to_string(i + 1);
		this->ideas[i] = Ideas.append(NumOfIdeas);
	}
}

std::string Brain::getAnIdeas( void ) const
{
	std::string idea = "no idea";
	int randomIdeas = 1 + (rand() % 100);

	idea = this->ideas[randomIdeas - 1];

	return (idea);
}

Brain::~Brain()
{
	std::cout << "Destructor for [ Brain ] class was called ..." << std::endl;
}

/* tkt */

//void Brain::IdeasBrain( void )
//{
//	this->ideas[0] = "I'm rightwing.";
//	this->ideas[1] = "I'm leftwing.";
//	this->ideas[2] = "je suis rasciste.";
//	this->ideas[3] = "je suis sexiste.";
//	this->ideas[4] = "je suis l'animal de Xavier.";
//	this->ideas[5] = "je suis pour l'égalité.";
//	this->ideas[6] = "je suis sûr que l'état veut notre mort.";
//	this->ideas[7] = "je suis communiste.";
//	this->ideas[8] = "je suis nazi.";
//	this->ideas[9] = "i have no ennemies";
//	this->ideas[10] = "I'm a man.";
//	this->ideas[11] = "I'm a woman.";
//	this->ideas[12] = "je veut faire du rap.";
//	this->ideas[13] = "je veut faire de a danse.";
//	this->ideas[14] = "I speak french, oui oui baguette.";
//	this->ideas[15] = "I speak German, /* CENSORED */.";
//	this->ideas[16] = "I speak Italian, pizza, pasta.";
//	this->ideas[17] = "I'm a boy.";
//	this->ideas[18] = "I'm a girl.";
//	this->ideas[19] = "GRIIIIFIIIIIIIITTTTTHHHHHHH !!!!.";
//	this->ideas[20] = "I'm a SHOTAKUN";
//	this->ideas[21] = "I want to touch some boobs";
//	this->ideas[22] = "Say what again MotherFucker";
//	this->ideas[23] = "[1]    42069 segmentation fault";
//	this->ideas[24] = "I'm Batman.";
//	this->ideas[25] = "/* Skuuuurt skuuuuuuuuurt */";
//	this->ideas[26] = "1/2 part of styrofoam, 1/2 part of unleaded gasoline.";
//	this->ideas[27] = "...___... (suzanne oscar suzanne)";
//	this->ideas[28] = "No, don't watch !";
//	this->ideas[29] = "CEEEEEAAAASAAAAAARRRR !";
//	this->ideas[30] = "(^_^) 8% | 3% (^_^)";
//	this->ideas[31] = "HYYYYYYYYYYYPE";
//	this->ideas[32] = "Tbh, the H isn't that bad, he's just realistic";
//	this->ideas[33] = "ok.";
//	this->ideas[34] = "How do I ctrl-c IRL ?";
//	this->ideas[35] = "Mmmmh Makima";
//	this->ideas[36] = "I wanna Fap Fap /* proceeds to fap fap */";
//	this->ideas[37] = "Let's go to France, it's legal";
//	this->ideas[38] = "If the age is on the clock, she is ready for the c...";
//	this->ideas[39] = "3 coppers and it's all yours";
//	this->ideas[40] = "Orphans on sale, everyone must go";
//	this->ideas[41] = "I want to help suicidal people";
//	this->ideas[41] = "Slaves should be free, I don't have any money";
//	this->ideas[42] = "C'est XAVIER Niel !";
//	this->ideas[43] = "Lolis are the best, but shotas are even better ! ^_^";
//	this->ideas[44] = "Au moins je t'ai rendu ton assiette";
//	this->ideas[45] = "M3 3L2"; 
//	this->ideas[46] = "Ouais c'est Greg";
//	this->ideas[47] = "Je suis spécial !";
//	this->ideas[48] = "Mon sac est fait !! Mon sac est fait !!";
//	this->ideas[49] = "Just keep your feet on the ground"
//	this->ideas[50] = "And move your head all around"
//	this->ideas[51] = "And put your hands in the air"
//	this->ideas[52] = "And move with the sound"
//	this->ideas[53] = "To the EARTHQUAKE !"
//	this->ideas[54] = "Ok mais est-ce que toi t'as des dragons terre 5 étoiles ?"
//	this->ideas[55] = "Poum poum *devient blanc*"
//	this->ideas[56] = "Zehahahaha hahaha *devient noir*"
//	this->ideas[57] = "The One PIeeeeeece the One Piece is rEAAAAAAAL (can we get much higher, so hiiiiiiiiigh oooohhooooh)"
//	this->ideas[58] = "IT'S JUST A GAAAAAAMMME DUDE !!!! HAHAHAHAHAHAHAHA !!"
//	this->ideas[59] = "I think i'm gay"
//	this->ideas[60] = "Why are you running ?"
//	this->ideas[61] = "Why are you gay ?"
//	this->ideas[62] = "C'est sous la terasse"
//	this->ideas[63] = "Today I fell... gay !"
//	this->ideas[64] = "Je suis pas raciste mais MLP..."
//	this->ideas[65] = "Débat parallèle ?"
//	this->ideas[66] = "Finale CDM"
//	this->ideas[67] = ""
//	this->ideas[68] = ""
//	this->ideas[69] = ""
//}