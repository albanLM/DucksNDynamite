#ifndef ACTIONS_H
#define ACTIONS_H


class Actions
{
public:
	Actions();

	bool quitGame() const;

	void setQuitGame(bool quitGame);

private:
	bool _quitGame = false;
};

#endif // ACTIONS_H
