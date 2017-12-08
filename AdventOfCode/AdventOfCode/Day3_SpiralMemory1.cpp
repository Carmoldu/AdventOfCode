#include<iostream>
#include<math.h>

using namespace std;

int spiralMemory1() {
	int count = 1, goal=289326,x=0,y=0, lastStep=0;
	bool flag = false;
	char lastMove = 'd';
	cout << "Count\tXpos\tYpos\tNextMove" << endl;
	cout << count << "\t" << x << "\t" << y << "\t";

	while (!flag) {

		switch (lastMove)
		{
		case 'd':
			//If previous move was down, move right
			count	+= lastStep + 1;
			x		+= lastStep + 1;

			lastStep++;
			lastMove='r';
			break;

		case 'r':
			//If previous move was right, move up
			count	+= lastStep;
			y		+= lastStep;

			lastMove = 'u';
			break;

		case 'u':
			//If previous move was up, move left
			count += lastStep + 1;
			x	  -= (lastStep + 1);

			lastStep++;
			lastMove = 'l';
			break;

		case 'l':
			//If previous move was left, move down
			count	+= lastStep;
			y		-= lastStep;

			lastMove = 'd';
			break;

		default:
			break;
		}

		if (count >= goal) {
			flag = true;
		}

		cout << lastStep << lastMove << endl << count << "\t" << x << "\t" << y << "\t";
	}


	switch (lastMove)
	{
	case 'd':
		//If last move was down, move up to the goal
		y += count - goal;
		break;

	case 'r':
		//If previous move was right, move left to the goal
		x -= count - goal;
		break;

	case 'u':
		//If previous move was up, move down to the goal
		y -= count - goal;
		break;

	case 'l':
		//If previous move was left, move right to the goal
		x += count - goal;
		break;

	default:
		break;
	}

	cout << endl << endl << "Final position is: (" << x << "," << y << ")" << endl;
	cout << "Manhattan discance is |x|+|y|= " << abs(x) + abs(y) << endl;

	return 0;
}