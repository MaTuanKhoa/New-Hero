#include <iostream>
#include <cstdlib>
using namespace std;
class Knight{
	public:
		string name;
	 	int hp;int max_hp;int heal_up;
		int def;
		int mdef;
		int atk;
		int matk;
		int mp;int max_mp;
		int crr;
		int exp;int lv_up;
		int lv;
		int hit_dame;
	
	void heal(){
		hp = hp + heal_up;
		if(max_hp<hp){
			hp=max_hp;
		}
	}
	
	void be_attacked(int dame,int mdame,int crit){
		if(dame!=0)
			hit_dame = (dame - def);
		if(mdame!=0)
			hit_dame = (mdame - mdef);
		if (hit_dame<0)
			hit_dame =0;
		if (crit==1){
			cout<<"\nCRIT DAME"<<endl;
			hit_dame = hit_dame*2;
		}
		cout <<"\ndame take: "<<hit_dame;
		hp = hp - hit_dame;
		hit_dame =0;
		cout<<"\nhp: "<<hp;
	}

	void show(){
		cout<<"\n"<<name<<endl;
		cout<<"hp: "<<hp<<"/"<<max_hp<<endl;
		cout<<"p.atk: "<<atk<<endl;
		cout<<"m.atk: "<<matk<<endl;
		cout<<"p.def: "<<def<<endl;
		cout<<"m.def: "<<def<<endl;
		cout<<"mp: "<<mp<<"/"<<max_mp<<endl;
		cout<<"crit rate: "<<crr<<"%"<<endl;
		if(lv!=0)
		cout<<"lv: "<<lv<<endl;
	}
	
	void lvup(){
		lv=lv+1;
		exp=exp-100;
		cout<<"\n*level up*"<<"\nLV: "<<lv<<endl;
		max_hp=max_hp+25;heal_up=heal_up+7;
		max_mp=max_mp+5;
		hp=max_hp;
		mp=max_mp;
		lv_up=lv_up+30;
		show();
	}
	void nextlv(){
		hp=hp+200;max_hp=max_hp+200;heal_up=heal_up+40;
		atk=atk+30;
		matk=matk+50;
		mdef=mdef+20;
		def=def+30;
		mp=mp+30;max_mp=max_mp+30;
		crr=25;
		lv=lv+1;
		show();	
	}
};
int main()
{
	string end;
	string lowmp;
	int difficult;
	int size=2;
	Knight s[size];
	Knight s1;
	cout<<"type knight name: ";
	getline(cin,s1.name);
	do{
		cout<<"type nunber of difficult (sever test just have 'easy''): ";
		cout<<"\n1.easy"<<"\n2.nomal"<<"\n3.hard"<<endl;
		cin>>difficult;
		cin.ignore();
		switch (difficult){
			case 1:
				s1.hp=100;s1.max_hp=100;s1.heal_up=25;
				s1.atk=50;
				s1.matk=90;
				s1.def=80;
				s1.mdef=30;
				s1.mp=30;s1.max_mp=30;
				s1.crr=35;
				s1.exp=0;
				s1.lv=1;s1.lv_up=100;
				break;
			default:
				cout<<"please type again: ";
		}
	}while(difficult!=1);
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"kinght: ";
	s1.show();
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
do{
	Knight s2;
	s2.name="Tigher";
	s2.hp=500;s2.max_hp=500;s2.heal_up=65;
	s2.atk=100;
	s2.matk=0;
	s2.mdef=10;
	s2.def=20;
	s2.mp=0;s2.max_mp=0;
	s2.crr=25;
	s2.lv=1;
	s2.show();
	do{
		int dame=0;
		int mdame=0;
		int action=0;
		int crit=0;
		int crit_rate=0;
		cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		do{
			lowmp="enough";
			cout<<"\n\ntype your action:";
			cout<<"\n1.attack"<<"\n2.skill(using MP)"<<"\n3.heal(hp + 25)"<<"\npress any key to skip turn to show infomation"<<endl;
			cin>>action;
			cin.ignore();
			switch (action){
				case 1:
					dame=s1.atk;
					break;
				case 2:
					if (s1.mp>=10){
					mdame = s1.matk;
					s1.mp=s1.mp-10;
					cout<<"\nyour MP: "<<s1.mp<<end;
					}
					else{
					cout<<"\nYOUR MP IS LOW"<<endl;
					lowmp="lowmp";
					}
					break;
				case 3:
					s1.heal();
					break;
				default:
					cout<<"\nyou skip turn"<<endl;
					s1.show();
			}
		cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		}while (lowmp=="lowmp");
		crit_rate= rand() % 100;
		if (crit_rate<s1.crr)
			crit=1;
		else
			crit=0;
		cout<<"\n\n\ntiger:";
		s2.be_attacked(dame,mdame,crit);
		dame=0;
		mdame=0;
		crit=0;
		do{	action= rand() % 3 + 1;
			lowmp="000";
			switch (action){
				case 1:
					dame=s2.atk;
					cout<<"\ntiger attack";
					break;
				case 2:
					if (s2.mp>=10){
					mdame = s2.matk;
					s2.mp=s2.mp-10;
					cout<<"\n~ tiger skill ~";
					}
					else{
					lowmp="lowmp";
					}
					break;
				case 3:
					s2.heal();
					cout<<"\nhealing heath";
					break;
				default:
					cout<<"\nyou skip turn"<<endl;
					
			}
		cout<<"\n................."<<endl;
		}while (lowmp=="lowmp");
		crit_rate= rand() % 100;
		if (crit_rate<s2.crr)
			crit=1;
		else
			crit=0;
		cout<<"\n\n"<<s1.name<<":";
		s1.be_attacked(dame,mdame,crit);
		dame=0;
		mdame=0;
		crit=0;
		if (s1.mp<=50){
			s1.mp=s1.mp+2;
		}
	}while(s1.hp>0 and s2.hp>0);
	if (s1.hp>0){
		cout<<"\n\nKNIGH WINS"<<endl;
		cout<<"\n"<<s1.name<<"+50 exp"<<endl;
		s1.exp=s1.exp+50;
	}
	else{
		cout<<"\n\nTIGER WINS"<<endl;
		end="no";
		}
	if (s1.lv_up<=s1.exp)
		s1.lvup();
	
	if (end!="no"){
		cout<<s1.exp<<"/"<<s1.lv_up<<" exp"<<endl;
		cout<<"\ndo you want to play again";
		cout<<"\n('no' to end game)";
		cout<<"\n('show' to show kight infomation)";
		cout<<"\n('next' to level up monter)"<<endl;
		getline(cin,end);
		while(end=="show"){
			s1.show();
			cout<<"\ndo you want to play again"<<"\n('no' to end game)"<<"\n('show' to show kight infomation)"<<endl;
			getline(cin,end);
		}
	}
	if (end=="next")
	s2.nextlv();
}while(end!="no");
}
