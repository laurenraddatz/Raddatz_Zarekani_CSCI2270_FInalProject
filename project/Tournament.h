#ifndef TOURNAMENT_H
#define TOURNAMENT_H
#include <string>


struct Gods{
	std::string name, attribute;
	int health, attack, agility;
	Gods  *parent, *left, *right;

	Gods(){};
	Gods(std::string in_name, std::string in_attribute, int in_health, int in_attack, int in_agility)
	{
		name = in_name;
		attribute = in_attribute;
		health = in_health;
		attack = in_attack;
		agility = in_agility;
		parent = NULL;
        	left = NULL;
        	right = NULL;
	}

};

class Tournament
{
    public:
        Tournament();
        ~Tournament();
        void InsertGod(std::string in_name, std::string in_attribute, int in_health, int in_attack, int in_agility);
        Gods *Fight(Gods *a, Gods *b);
        void printGods(int tier_choice);
        bool findGod(std::string in_name);
        void playerControl(Gods *a, Gods *b);
        void deleteGod(int index);
        void manualFight(Gods *a, Gods *b);
        void deleteAll(Gods *node);
        void makeGod(std::string in_name, std::string in_attribute, std::string in_dominantStat, std::string in_inferiorStat);
        Gods* getRoot();
        void makeTree();
        void runTournament();

    protected:

    private:
        int godSize = 8;
        Gods *godList[8];
        Gods *root;
        Gods *player;
};

#endif // TOURNAMENT_H
