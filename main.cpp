#include <iostream>
#include <string>

using namespace std;

class Config{
	private:
		int shift;
		char case_strategy;
	public:
		Config():shift{0},case_strategy{0}{}
		~Config() = default;
		
		void set_shift(int shift)
		{
			this->shift = shift;
		}
		
		void set_case(char new_case)
		{
			case_strategy = new_case;
		}
		
		int get_shift(){return shift;}
		char get_case(){return case_strategy;}
};

int main()
{
	int shift,i=0;
	unsigned char query,inquery,character,case_sensitivity;
    string paragraph; 
	
	Config crypto_Config;
	
	cout << "Encrypt/Decrypt Using Ceaser Ciphr" << endl;
	cout << "Configurations" << endl;
	
	cout << "Enter Number of shifts" <<endl;
	cin >> shift;
	crypto_Config.set_shift(shift);
	cout << "Character will be shifted by: " << crypto_Config.get_shift() << ", for example: a -> "<< char('a' + crypto_Config.get_shift()) <<endl;
	
	cout << "Enter Case Sensitivity"<< endl << "Choose From : "<<endl<<"1. For Ignore Case press [I]"<<endl<<"2. For Case Sensitive press [S]"<<endl;
	cin >> case_sensitivity;
	crypto_Config.set_case(case_sensitivity);
	cout << "You Have Choosed: "<< ((crypto_Config.get_case()=='I' || crypto_Config.get_case() == 'i')?"Ignore Case":"Case Sensitive")<<endl;
	
	while(1)
	{
		
		cout<<"Press [E] to Encrypt a paragraph"<<endl;
		cout<<"Press [D] to Decrypt a paragraph"<<endl;
		cout<<"Press [C] to Change the configuration"<<endl;
		cout<<"Press [Q] to Close Cryptography Program"<<endl;
	  
		cin>>query;
		
		if(query == 'E' || query == 'e')
		{
			cout << "Enter a paragraph of text:" << endl; 
			cin.ignore();
			getline(cin, paragraph);
			if(crypto_Config.get_case() == 'I' || crypto_Config.get_case() == 'i')
			{
				while(paragraph[i] != NULL)
				{
					if(paragraph[i] >= 'a' && paragraph[i] <= 'z')
					{
						character = char(paragraph[i] +crypto_Config.get_shift());
						
						if(character > 'z')
						{
							character -=  26;
						}
						else
						{
							//Do Nothing
						}
						
						paragraph[i] = character;
					}
					else if(paragraph[i] >= 'A' && paragraph[i] <= 'Z')
					{
						character = char(paragraph[i] + 32 + crypto_Config.get_shift());
						if(character > 'z')
						{
							character -= 26;
						}
						paragraph[i] = character;
					}
					i++;
				}

			}
			else if(crypto_Config.get_case() == 'S' || crypto_Config.get_case() == 's')
			{
				while(paragraph[i] != NULL)
				{
					if(paragraph[i] >= 'a' && paragraph[i] <= 'z')
					{
						character = char(paragraph[i] +crypto_Config.get_shift());
						if(character > 'z')
						{
							character -= 26;
						}
						paragraph[i] = character;
					}
					else if(paragraph[i] >= 'A' && paragraph[i] <= 'Z')
					{
						character = char(paragraph[i] + crypto_Config.get_shift());
						if(character > 'Z')
						{
							character -= 26;
						}
						paragraph[i] = character;
					}
					i++;
				}
			}
			
			cout << "Paragraph after Encryption:\n" << paragraph << endl; 
			
			cout<<"Press [c] to Clear Screen"<<endl;
			cin>>inquery;
			
			if(inquery == 'c' || inquery == 'C')
			{
				system("cls");
			}
			else
			{
				//Do Nothing
			}
		
		}
		else if(query == 'D' || query == 'd')
		{
			cout << "Enter a paragraph of text:" << endl; 
			cin.ignore();
			getline(cin, paragraph);
			if(crypto_Config.get_case() == 'I' || crypto_Config.get_case() == 'i')
			{
				while(paragraph[i] != NULL)
				{
					if(paragraph[i] >= 'a' && paragraph[i] <= 'z')
					{
						character = char(paragraph[i] - crypto_Config.get_shift());
						
						if(character < 'a')
						{
							character +=  26;
						}
						else
						{
							//Do Nothing
						}
						
						paragraph[i] = character;
					}
					else if(paragraph[i] >= 'A' && paragraph[i] <= 'Z')
					{
						character = char(paragraph[i] + 32 - crypto_Config.get_shift());
						if(character < 'a')
						{
							character += 26;
						}
						paragraph[i] = character;
					}
					i++;
				}

			}
			else if(crypto_Config.get_case() == 'S' || crypto_Config.get_case() == 's')
			{
				while(paragraph[i] != NULL)
				{
					if(paragraph[i] >= 'a' && paragraph[i] <= 'z')
					{
						character = char(paragraph[i] - crypto_Config.get_shift());
						if(character < 'a')
						{
							character += 26;
						}
						paragraph[i] = character;
					}
					else if(paragraph[i] >= 'A' && paragraph[i] <= 'Z')
					{
						character = char(paragraph[i] - crypto_Config.get_shift());
						if(character < 'A')
						{
							character += 26;
						}
						paragraph[i] = character;
					}
					i++;
				}
			}
			cout << "Paragraph after Decryption:\n" << paragraph << endl; 
			
			cout<<"Press [c] to Clear Screen"<<endl;
			cin>>inquery;
			
			if(inquery == 'c' || inquery == 'C')
			{
				system("cls");
			}
			else
			{
				//Do Nothing
			}
		}
		if(query == 'C' || query == 'c')
		{
			system("cls");
			cout<<"Are you sure to change the Configurations?"<<endl;
			cout<<"Press [y] to continue on same configurations"<<endl;
			cout<<"Press [n] to change configurations "<<endl;
			cin>>inquery;
			
			if(inquery == 'y' || inquery == 'Y')
			{
				cout << "Enter Number of shifts" <<endl;
				cin >> shift;
				crypto_Config.set_shift(shift);
				cout << "Character will be shifted by: " << crypto_Config.get_shift() << ", for example: a -> "<< char('a' + crypto_Config.get_shift()) <<endl;
				
				cout << "Enter Case Sensitivity"<< endl << "Choose From : "<<endl<<"1. For Ignore Case press [i]"<<endl<<"2. For Case Sensitive press [s]"<<endl;
				cin >> case_sensitivity;
				crypto_Config.set_case(case_sensitivity);
				cout << "You Have Choosed: "<< (crypto_Config.get_case()=='i'?"Ignore Case":"Case Sensitive")<<endl;
			}
			else if(inquery == 'n' || inquery == 'N')
			{
				//Do Nothing
			}
			
		}
		else if(query == 'Q' || query == 'q')
		{
			system("cls");
			cout<<"Thank you for using Cryptography Program"<<endl;
			break;
		}
		i = 0;
	
	}
	
	return 0;
}
