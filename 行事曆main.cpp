#include<iostream>
#include<cstring>
using namespace std;

class Schedule{
	public:
		Schedule();
		Schedule(int,int,string,string);
		
		saveMonth(int);
		saveDay(int);
		saveLocation(string);
		saveSchedule(string);
		
		deleteData();
		
		getMonth();
		getDay();
		
		printSchedule();
		
	private:
		int month;
		int day;
		string location;
		string schedule;
};

void searchAllDate(int,int,int);
void searchWeek(int,int,int);
int searchDate(int,int,int);

Schedule data[11];

int main(){
	bool endCheck=1;
	int i,inputAction,inputDateOrWeek,inputMonth,inputDay,dataCount=0;
	string inputPerson,inputLocation,inputSchedule;
	
	cout<<"請輸入使用者名稱：";
	
	cin>>inputPerson;
	
	cout<<endl<<inputPerson<<" 歡迎使用本系統"<<endl; 
	
	for(;endCheck;){
		
		fflush(stdin);
		cin.clear();
		
		cout<<endl;
		cout<<"請選擇行動(輸入代號)："<<endl;
		cout<<"(1)查詢"<<endl;
		cout<<"(2)紀錄"<<endl;
		cout<<"(3)修改行程"<<endl;
		cout<<"(4)刪除"<<endl;
		cout<<"(5)離開"<<endl;
		cout<<endl;
		
		cin>>inputAction;
		
		cout<<endl;
		
		switch(inputAction){
			case 1:
				cout<<"請選擇："<<endl;
				cout<<"(1)印出指定日期行程"<<endl;
				cout<<"(2)印出指定星期行程"<<endl;
				cout<<endl;
				
				cin>>inputDateOrWeek;
				
				cout<<endl;
				
				switch(inputDateOrWeek){
					case 1:
						cout<<"請輸入日期 (月 日)："<<endl;
						
						cin>>inputMonth>>inputDay;
						
						searchAllDate(inputMonth,inputDay,dataCount);
						
						break;
					
					case 2:
						cout<<"請輸入星期首日日期 (月 日)："<<endl;
						
						cin>>inputMonth>>inputDay;
						
						searchWeek(inputMonth,inputDay,dataCount);
						
						break;
					
					default:
						cout<<"錯誤輸入"<<endl;
						
						break; 
				} 
				
				break;
			
			case 2:
				if(dataCount>=10){
					cout<<"行程已滿"<<endl;
					break; 
				}
				
				cout<<"請輸入日期 (月 日)："<<endl;
				
				cin>>inputMonth>>inputDay;
				
				i=dataCount;
				
				data[i].saveMonth(inputMonth);
				data[i].saveDay(inputDay); 
				
				cout<<"請輸入地點："<<endl;
				
				cin>>inputLocation;
				
				data[i].saveLocation(inputLocation); 
				
				cout<<"請輸入行程："<<endl;
				
				cin>>inputSchedule;
				
				data[i].saveSchedule(inputSchedule);
				
				dataCount++;
				
				break;
				
			case 3:
				cout<<"請輸入日期 (月 日)："<<endl;
				
				cin>>inputMonth>>inputDay;
				
				i=-1;
				
				i=searchDate(inputMonth,inputDay,dataCount);
				
				if(i>=0){
					
					cout<<"請輸入修改後的地點："<<endl;
					
					cin>>inputLocation;
					
					data[i].saveLocation(inputLocation);
				
					cout<<"請輸入修改後的行程："<<endl;
				
					cin>>inputSchedule;
				
					data[i].saveSchedule(inputSchedule);
				}
				
				else cout<<"未找到行程或錯誤輸入"<<endl; 
				
				break;
			
			case 4:
				cout<<"請輸入日期 (月 日)："<<endl;
				
				cin>>inputMonth>>inputDay;
				
				i=-1;
				
				i=searchDate(inputMonth,inputDay,dataCount);
				
				if(i>=0) data[i].deleteData();
				
				else cout<<"未找到行程或錯誤輸入"<<endl;
				
				break;
				
			case 5:
				cout<<"感謝您使用本系統"<<endl;
				
				endCheck=0; 
				
				break;
				
			default:
				cout<<"錯誤輸入"<<endl;
				
				break; 
		} 
	}
} 

Schedule::Schedule(){
	month=0;
	day=0;
	location.clear();
	schedule.clear();
}

Schedule::Schedule(int m,int d,string l,string s){
	saveMonth(m);
	saveDay(d);
	saveLocation(l);
	saveSchedule(s);
}
		
Schedule::saveMonth(int M){
	if(M<1) month=1;
	else if(M>12) month=12;
	else month=M; 
}

Schedule::saveDay(int D){
	int dateOfMonth[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
	if(D<1) day=1;
	else if(D>dateOfMonth[month]) day=dateOfMonth[month];
	else day=D;
}

Schedule::saveLocation(string L){
	location=L;
}

Schedule::saveSchedule(string S){
	schedule=S;
}
		
Schedule::deleteData(){
	month=0;
	day=0;
	location.clear();
	schedule.clear();
}

Schedule::getMonth(){
	return month;
}

Schedule::getDay(){
	return day;
}
		
Schedule::printSchedule(){
	cout<<endl;
	cout<<"日期： "<<getMonth()<<"月 "<<getDay()<<"日"<<endl;
	cout<<"地點： "<<location<<endl;
	cout<<"行程： "<<schedule<<endl;
}

void searchAllDate(int m,int d,int count){
	int printCount=0;
	for(int j=0;j<count;){
		if(m==data[j].getMonth() && d==data[j].getDay()){
			data[j].printSchedule();
			printCount++;
		}
		j++;
	}
	if(printCount==0){
		cout<<"本日沒有行程或錯誤輸入"<<endl; 
	}
	return;
}

void searchWeek(int m,int d,int count){
	int dateOfMonth[13]={0,31,29,31,30,31,30,31,31,30,31,30,31},printCount=0;
	for(int k=0;k<7;k++){
		for(int j=0;j<count;){
			if(m==data[j].getMonth() && d==data[j].getDay()){
				data[j].printSchedule();
				printCount++;
			}
			j++;
		}
		d++;
		if(d>dateOfMonth[m]){
			d=1;
			m++;
		}
	}
	if(printCount==0){
		cout<<"本日沒有行程或錯誤輸入"<<endl; 
	}
	return;
}

int searchDate(int m,int d,int count){
	int dateOfMonth[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
	int sameNum[11],sameCount,inputNum=-1,k;
	if(m>12 || m<0 || d<0 || d>dateOfMonth[m]) return -1;
	for(int j=0;j<count;j++){
		if(m==data[j].getMonth() && d==data[j].getDay()){
			sameNum[sameCount]=j;
			sameCount++;
		}
	}
	if(sameCount==0) return -1;
	else if(sameCount==1) return sameNum[0];
	else{
		cout<<"本日有多於一項行程，請選擇其中一項："<<endl; 
		for(k=0;k<sameCount;k++){
			cout<<endl<<"("<<k<<")"<<endl;
			data[sameNum[k]].printSchedule();
		}
		cin>>inputNum;
		if(inputNum>=0 && inputNum<sameCount) return sameNum[inputNum];
		else return -1;
	}
}
