/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int days(int, int, int, int, int, int);
int months(int, int);
int mon[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

struct node{
	int data;
	struct node *next;
};


int between_days(struct node *date1head, struct node *date2head){
	if (date1head==NULL || date2head==NULL)
	return -1;
	int i;
	int d1=0, d2=0, m1=0, m2=0, y1=0, y2=0;
	struct node *temp1 = date1head;
	struct node *temp2 = date2head;
	
	for (i = 0; i < 2; i++)
	{
		d1 = d1 * 10 + temp1->data;
		temp1 = temp1->next;
		d2 = d2 * 10 + temp2->data;
		temp2 = temp2->next;
	}
	for (i = 2; i < 4; i++)
	{
		m1 = m1 * 10 + temp1->data;
		temp1 = temp1->next;
		m2 = m2 * 10 + temp2->data;
		temp2 = temp2->next;
	}
	for (i = 4; i < 8; i++)
	{
		y1 = y1 * 10 + temp1->data;
		temp1 = temp1->next;
		y2 = y2 * 10 + temp2->data;
		temp2 = temp2->next;
	}
	if (y1 == y2 && m1 == m2 && d1 == d2) return 0;
	if (y1 == y2 && m1 == m2 && (d2 - d1) == 1) return 0;
	int diff = days(y1, y2, m1, m2, d1, d2);
	return (diff-1);
}

int days(int y1, int y2, int m1, int m2, int d1, int d2)
{
	int count = 0, i;
	for (i = y1; i < y2; i++)
	{
		if (i % 4 == 0)
			count += 366;
		else
			count += 365;
	}
	count -= months(m1, y1);
	count -= d1;
	count += months(m2, y2);
	count += d2;
	if (count<0)
		count = count*-1;
	return count;
}

int months(int m, int y)
{
	int t = 0, c;
	for (c = 0; c<m - 1; c++)
	{
		if (c == 1)
		{
			if (y % 4 == 0)
				t += 29;
			else
				t += 28;
		}
		else
			t += mon[c];
	}
	return(t);
}
