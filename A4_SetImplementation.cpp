/*

Problem statement(set_adt) :=
To create ADT that implement the "set" concept.
a. Add (new Element) -Place a value into the set ,
b. Remove (element) Remove the value
c. Contains (element) Return true if element is in collection,
d. Size () Return number of values in collection Iterator () Return an iterator used to loop over collection,
e.Intersection of two sets ,
f. Union of two sets,
g. Difference between two sets,
h. Subset

*/
#include <bits/stdc++.h>
using namespace std;
class set1
{
public:
	int arr1[20];
	int arr2[20];
	set1()
	{
		for (int i = 0; i < 20; i++)
		{
			arr1[i] = -1;
			arr2[i] = -1;
		}
	}
	int insert(int arr[])
	{
		int key;
		cout << "Enter a element to insert:";
		cin >> key;
		int loc = 0;

		for (int i = 0; i < 20; i++)
		{

			if (arr[loc] == -1)
			{
				arr[loc] = key;
			}
			else if (arr[loc] != -1 && arr[loc] == key)
			{
				break;
			}
			else
			{
				loc = loc + 1;
			}
		}
	}
	void display()
	{
		for (int i = 0; i < 20; i++)
		{
			if (arr1[i] == -1)
			{
				cout << "--" << endl;
			}
			else
			{

				cout << arr1[i] << endl;
			}
		}
	}
	void del()
	{
		int key;
		cout << "Enter Element to delete:";
		cin >> key;
		int i;
		int n = 20;
		for (i = 0; i < n; i++)
		{
			if (arr1[i] == key)
			{
				break;
			}
		}
		if (i < n)
		{
			n--;
			for (int j = i; j < n; j++)
			{
				arr1[j] = arr1[j + 1];
			}
		}
	}
	void search()
	{
		int search;
		bool flag = false;
		cout << "Enter the search element:";
		cin >> search;
		for (int i = 0; i < 20; i++)
		{
			if (arr1[i] == search)
			{
				flag = true;
				break;
			}
		}
		if (flag)
		{
			cout << "Element is found";
		}
		else
		{
			cout << "Element not found";
		}
	}

	int count(int arr[])
	{
		int cnt = 0;
		for (int i = 0; i < 20; i++)
		{
			if (arr[i] != -1)
			{
				cnt++;
			}
		}

		return cnt;
	}

	void union1()
	{
		int flag;
		string reply;
		cout << "Enter 1st set";
		do
		{
			insert(arr1);
			cout << "Do you want to continue(y/n):";
			cin >> reply;
		} while (reply != "n");

		cout << "Enter 2nd set:";
		do
		{
			insert(arr2);
			cout << "Do you want to continue(y/n):";
			cin >> reply;
		} while (reply != "n");
		int m = count(arr1);
		int n = count(arr2);
		int arr3[20];
		int k = 0;
		for (int i = 0; i < m; i++)
		{
			arr3[k] = arr1[i];
			k++;
		}
		for (int i = 0; i < n; i++)
		{
			flag = 0;
			for (int j = 0; j < m; j++)
			{
				if (arr2[i] == arr1[j])
				{
					flag = 1;
					break;
				}
			}
			if (flag != 1)
			{
				arr3[k] = arr2[i];
				k++;
			}
		}

		cout << "Union: ";
		for (int i = 0; i < k; i++)
		{
			if (arr3[i] == -1)
			{
				break;
			}
			else
			{
				cout << arr3[i] << ",";
			}
		}
	}

	void intersection1()
	{
		string reply;
		cout << "Enter 1st set";
		do
		{
			insert(arr1);
			cout << "Do you want to continue(y/n):";
			cin >> reply;
		} while (reply != "n");

		cout << "Enter 2nd set:";
		do
		{
			insert(arr2);
			cout << "Do you want to continue(y/n):";
			cin >> reply;
		} while (reply != "n");
		int m = count(arr1);
		int n = count(arr2);
		int arr3[20];
		int k = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (arr1[i] == arr2[j])
				{
					arr3[k] = arr1[i];
					k++;
				}
			}
		}
		cout << "Intersection: ";
		for (int i = 0; i < k; i++)
		{
			if (arr3[i] == -1)
			{
				break;
			}
			else
			{
				cout << arr3[i] << ",";
			}
		}
	}
	void difference1()
	{
		string reply;
		cout << "Enter 1st set";
		do
		{
			insert(arr1);
			cout << "Do you want to continue(y/n):";
			cin >> reply;
		} while (reply != "n");

		cout << "Enter 2nd set:";
		do
		{
			insert(arr2);
			cout << "Do you want to continue(y/n):";
			cin >> reply;
		} while (reply != "n");
		int m = count(arr1);
		int n = count(arr2);
		int arr3[20];
		int k = 0;
		int flag = 0;
		for (int i = 0; i < m; i++)
		{
			flag = 0;
			for (int j = 0; j < n; j++)
			{
				if (arr1[i] == arr2[j])
				{
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{

				arr3[k] = arr1[i];
				k++;
			}
		}
		cout << "Difference(A-B): ";
		for (int i = 0; i < k; i++)
		{
			if (arr3[i] == -1)
			{
				break;
			}
			else
			{
				cout << arr3[i];
			}
		}
	}
	int subSets()
	{
		string reply;
		cout << "Enter 1st set";
		do
		{
			insert(arr1);
			cout << "Do you want to continue(y/n):";
			cin >> reply;
		} while (reply != "n");

		cout << "Enter subset:";
		do
		{
			insert(arr2);
			cout << "Do you want to continue(y/n):";
			cin >> reply;
		} while (reply != "n");
		int m = count(arr1);
		int n = count(arr2);

		int i=0;
		int j=0;
		for ( i = 0; i < n; i++)
		{
			for ( j = 0; j < m; j++)
			{
				if (arr2[i] == arr1[j])
					break;
			}
			if (j == m)
				return 0;
		}
		return 1;
	}
};
int main()
{
	set1 s;
	int ch;
	int count;
	int  check;
	while (1)
	{
		cout << "\n1.Insert\n2.Display\n3.Delete\n4.Search\n5.Count\n6.Union\n7.Intersection\n8.Difference\n9.subsets\n10.Exit\n";
		cout << "Enter a choice:";
		cin >> ch;
		switch (ch)
		{
		case 1:
			s.insert(s.arr1);
			break;
		case 2:
			s.display();
			break;
		case 3:
			s.del();
			break;
		case 4:
			s.search();
			break;
		case 5:
			count = s.count(s.arr1);
			cout << "No Of Elements In set :" << count << endl;
			break;
		case 6:
			s.union1();
			break;
		case 7:
			s.intersection1();
			break;
		case 8:
			s.difference1();
			break;
		case 9:
			check=s.subSets();
			if(check){
				cout<<"Array 2 is subset of array 1"<<endl;
			}
			else{
				cout<<"Array 2 is not a subset of array 1"<<endl;
			}
			break;
		case 10:
			exit(1);
		default:
			cout << "Enter a valid choice";
		}
	}
	return 0;
}
