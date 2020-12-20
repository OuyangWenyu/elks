/*
 * part_4.cpp
 *
 *  Created on: 2017年4月5日
 *      Author: asus
 */
#include <iostream>
#include <iomanip>
using namespace std;
enum WarriorType{
	 dragon,ninja,iceman,lion,wolf
};
/*class Warrior{
private:
	int id;//编号
	int healthpoint;//生命值
	int agressivity;//攻击力
	WarriorType wt;//武士类型
};*/
class HeadQuarter{
private:
	string name;
	int num;//武士总数，从0开始
	int lifeElement;//生命元个数
	int order[5];//生成武士顺序编号，与enum中各类型对应
	int index;//当前产生武士类型的编号，如当前武士是ninja，则对应编号为ninja在order中的顺序编号，起始值为0
	int clock;//当前时间
	int hps[5];//生成的各个武士的生命元个数
	int nums[5];//武士类型的个数
	bool ending;//是否结束
public:
	bool getEnding(){return ending;}
	HeadQuarter(string n,int le,int o[5],int h[5]):name(n),num(0),lifeElement(le),index(0),clock(0),ending(false){
		for(int i=0;i<5;i++){
			order[i]=o[i];
			hps[i]=h[i];
			nums[i]=0;
		}
	}
	string typeByIndex(){
		string wt;
		switch(order[index]){
		case 0:
			wt="dragon";
			break;
		case 1:
			wt="ninja";
			break;
		case 2:
			wt="iceman";
			break;
		case 3:
			wt="lion";
			break;
		case 4:
			wt="wolf";
			break;
		}
		return wt;
	}
	void generate(){//根据当前生命元个数判断能否产生一个新武士
		/*制造一个初始生命值为m的武士，司令部中的生命元就要减少m个。
		如果司令部中的生命元不足以制造某个按顺序应该制造的武士，
		那么司令部就试图制造下一个。如果所有武士都不能制造了，则司令部停止制造武士。*/
		int temp=0;
		while(lifeElement<hps[index] && temp<5){
			index=(index+1)%5;
			temp++;
		}
		if(temp>=5){
			cout<<std::setfill('0')<< std::setw(3)<<clock<<" "<<name
					<<" headquarter stops making warriors"<<endl;
			ending=true;
		}else{
			num++;
			nums[index]++;
			cout<<std::setfill('0')<< std::setw(3)<<clock<<" "<<name<<" "
					<<typeByIndex()<<" "<<num<<" born with strength "
					<<hps[index]<<","<<nums[index]<<" "<<typeByIndex()
					<<" in "<< name<<" headquarter"<<endl;
			lifeElement=lifeElement-hps[index];
			index=(index+1)%5;
			clock++;
		}
	}
};

int main(){
	int n;//测试数据组数
	cin>>n;
	for(int i=0;i<n;i++){
		int M;
		cin>>M;//每个司令部起始生命元个数
		int hps[5];
		cin>>hps[0]>>hps[1]>>hps[2]>>hps[3]>>hps[4];
		int reds[5]={2,3,4,1,0};
		int redhps[5]={hps[2],hps[3],hps[4],hps[1],hps[0]};
		int blues[5]={3,0,1,2,4};
		int bluehps[5]={hps[3],hps[0],hps[1],hps[2],hps[4]};
		HeadQuarter red("red",M,reds,redhps);
		HeadQuarter blue("blue",M,blues,bluehps);
		cout<<"Case:"<<i+1<<endl;
		while(!red.getEnding() || !(blue.getEnding())){
			if(!red.getEnding())
				red.generate();
			if(!blue.getEnding())
				blue.generate();
		}
	}
	return 0;
}



