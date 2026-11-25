#include<bits/stdc++.h>
#include<windows.h>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)

using namespace std;
// class Tower {
// 	protected:
// 		int x,y;
// 		long long range,damage;
// 		long long health;
// };
// class Factor {
// 	protected:
// 		int x,y;
// 		long long zy;//囤积资源
// 		long long health;
// };
// class Ziyuan {
// 	protected:
// 		int x,y;
// 		long long cun;//存储的资源
// 		long long health;
// };
// struct Node {
// 	int id;
// 	Tower* tow;
// 	Factor* fac;
// 	Ziyuan* zi;
// 	public:
// 		int zhan;
// 		void gzhan(){
// 			zhan = (tow!=nullptr || fac!=nullptr || zi!=nullptr);
// 		}
// };
int nandu;
int zx,zy;
// Node mp[52][52];
int mp[52][52];
string name;
vector<string> jianzhu[6] = {{},{"水晶矿脉","高    山","森    林","铜矿矿脉","煤矿矿脉","铀矿矿脉"},{"水晶矿机","采石 机 ","伐木 场 ","铜矿矿机","煤矿矿机","太阳能板","铀矿矿机"},{"炮弹工厂","弓箭工厂","护盾生成","炼钢 厂 ","核反应堆"},{"城    墙","大    炮","箭    塔","闪电 塔 ","激光炮塔","尖    刺"},{"信号中继","研究 室 ","炮弹仓库","弓箭仓库","电力仓库","资源仓库"}};
//std::string kuangji[7] = {"水晶矿机","采石机 ","伐木场 ","铜矿矿机","煤矿矿机","太阳能板","铀矿矿机"},gongchang[5] = ,fangyv[7] = , ziyuan[6] = ;




int ti(float a) {
	return ((int)(a*10+5))/10;
}
void Setpos(float x,float y){COORD pos;pos.X=ti(y*4)/2;pos.Y=ti(x);SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);}
void make_mp(int n,int m,std::vector<int> vein);
void dd();
void cd();
void print(int n,int m);

//main

int main() {
//	ios::sync_with_stdio(0);
	system("title 塔防v1.0");
	int choose=1;//选项
	choose=MessageBox(GetConsoleWindow(), TEXT("是否读档"), TEXT("读档提示"), MB_YESNO);
	system("cls");
	if(choose==6) {
		dd();
	} else {
		system("mode con cols=209 lines=50");
		//printf("")
		Setpos(0,0);

		printf("选择难度:1简单,2普通,3困难,4沙盒\n");
		cin>>nandu;
		printf("难度%d ?",nandu);
	}
	Sleep(500);
	
	std::vector<int> vein(6);//	共75
	vein[0] = 10,vein[1] = 15,vein[2] = 15,vein[3] = 13,vein[4] = 12,vein[5] = 10;
	system("cls");
	make_mp(50,50,vein);
	while(1){
		zx = 10+rand()%30, zy = 10+rand()%30;
		if(mp[zx][zy]==0){
			mp[zx][zy] = -1;
			break;
		}
	}
	
	for(int i = 0;i<50;i++){
		for(int j = 0;j<50;j++){
			printf("%3d",mp[i][j]);
		}
		cout<<'\n';
	}
	Sleep(500);
	system("cls");
	
	
	int prn = 1,prm = 1;
	while(1){
		print(prn,prm);
		if(KEY_DOWN('W') || KEY_DOWN(VK_UP)){
			if(prn>-10)prn--;
		}
		if(KEY_DOWN('A') || KEY_DOWN(VK_LEFT)){
			if(prm>-10)prm--;
		}
		if(KEY_DOWN('S') || KEY_DOWN(VK_DOWN)){
			if(prn<70)prn++;
		}
		if(KEY_DOWN('D') || KEY_DOWN(VK_RIGHT)){
			if(prm<40)prm++;
		}
		Sleep(40);
	}
	return 0;
}

//function

void cd() {
	system("cls");
	if(name.empty()) {
		printf("名称：");
		getline(cin,name);
		name+=".json";
	}
	system("cls");
	printf("正在存档,请稍后 . . . . . . ");
	FILE *fp=fopen(name.c_str(),"wb");
	for(int x=1; x<=50; x++) {
		for(int y=1; y<=50; y++) {
			fprintf(fp,"%d ",mp[x][y]);
		}
		fprintf(fp,"\n");
	}
	cout<<nandu;
	fclose(fp);
	system("cls");
	printf("存档成功！");
	Sleep(2000);
	exit(0);
}
void dd() {
	system("cls");
	printf("name(别加后缀):");
	std::getline(std::cin,name);
	name+=".json";
	FILE* fp=fopen(name.c_str(),"rb");
	if(fp==NULL) {
		system("cls");
		printf("无法打开文件进行读取");
		exit(0);
	}
	for(int i=1; i<=50; i++) {
		for(int j=1; j<=50; j++) {
			fscanf(fp,"%d",&mp[i][j]);
		}
	}
	fscanf(fp,"%d",&nandu);
	fclose(fp);
	system("cls");
	printf("读档成功！");
	Sleep(2000);
	return;
}
void make_mp(int n,int m,std::vector<int> vein) { //‖
	int a[5][2] = {{-1,0},{0,-1},{0,0},{0,1},{1,0}};
	srand(time(0));
	for(int i = 0; i<vein.size(); i++) {
		for(int j = 0; j<vein[i]; j++) {
			int x = 2+rand()%(n-2), y = 2+rand()%(m-2);
			//cout<<114514;
			bool bi = true;//标记未占用
			for(int k = 0; k<5; k++) {
				if(mp[x+a[k][0]][y+a[k][1]]!=0){ bi = false;break;}
			}
			if(bi) {
				mp[x][y] = 10+(i);
			}
		}
	}
	return;
}
void print(int n,int m){
//	system("cls");
	Setpos(0,0);
	for(int i = n;(i)<n+40;i++){
		string s = "";
		for(int j = m;(j)<m+20;j++){
			if((i>>1)<1 || (j)<1 || (i>>1)>50 || (j)>50){
				s+="    ";
			}else{
				if(mp[i>>1][j]==0){
					s+="   0";
				}else if(mp[i>>1][j]==-1){
					if(i%2 == 0){
						s+="主基";
					}else{
						s+=" 地 ";
					}
				}else{
					if(i%2==0){
						string s1 = "";
						s1.push_back(jianzhu[mp[i>>1][j]/10][mp[i>>1][j]%10][0]);
						s1.push_back(jianzhu[mp[i>>1][j]/10][mp[i>>1][j]%10][1]);
						s1.push_back(jianzhu[mp[i>>1][j]/10][mp[i>>1][j]%10][2]);
						s1.push_back(jianzhu[mp[i>>1][j]/10][mp[i>>1][j]%10][3]);
						s+=s1;
					}else{
						string s1 = "";
						s1.push_back(jianzhu[mp[i>>1][j]/10][mp[i>>1][j]%10][4]);
						s1.push_back(jianzhu[mp[i>>1][j]/10][mp[i>>1][j]%10][5]);
						s1.push_back(jianzhu[mp[i>>1][j]/10][mp[i>>1][j]%10][6]);
						s1.push_back(jianzhu[mp[i>>1][j]/10][mp[i>>1][j]%10][7]);
						s+=s1;
					}
					
				}
			}
		}
//		if(i!=n+20)
			s+="\n";
		cout<<s;
	}
	return;
}
