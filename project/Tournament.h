#ifndef TOURNAMENT_H
#define TOURNAMENT_H
#include <string>


struct Gods{
	std::string name, attribute, speech;
	int health, attack, agility;
	Gods  *parent, *left, *right;

	Gods(){};
	Gods(std::string in_name, std::string in_attribute, int in_health, int in_attack, int in_agility, std::string in_speech)
	{
		name = in_name;
		attribute = in_attribute;
		health = in_health;
		attack = in_attack;
		agility = in_agility;
		speech = in_speech;
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
        void InsertGod(std::string in_name, std::string in_attribute, int in_health, int in_attack, int in_agility, std::string in_speech);
        Gods *Fight(Gods *a, Gods *b);
        void printGods(int tier_choice);
        bool findGod(std::string in_name);
        void playerControl(Gods *a, Gods *b);
        void deleteGod(int index);
        Gods* manualFight(Gods *a, Gods *b);
        void deleteAll(Gods *node);
        void makeGod(std::string in_name, std::string in_attribute, std::string in_dominantStat, std::string in_inferiorStat, std::string in_speech);
        Gods* getRoot();
        void runTournament();
        void readFile();
        void InitializeTourny();
        void findGodHistory(std:: string in_name, Gods* winner);
        Gods *player;
        
    protected:

    private:
        int godSize;
        Gods *godList[8];
        Gods *root;
        int round = 1;
};

#endif // TOURNAMENT_H
