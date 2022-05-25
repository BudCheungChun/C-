#include <iostream>
using namespace std;
class Remote;

class TV {
	friend class Remote;
private:
	int m_State;
	int m_Vol;
	int m_Channel;
public:
	enum{on,off};
	enum{minVol = 0,maxVol = 100};
	enum{minChannel = 1,maxChannel = 255};
	TV() {
		m_State = off;
		m_Vol = minVol;
		m_Channel = minChannel;
	}
	void switch_On_Off() {
		m_State = (m_State == on ? off : on);
	}
	void vol_Up() {
		if (m_Vol == maxVol) {
			return;
		}
		m_Vol++;
	}
	void vol_Down() {
		if (m_Vol == minVol) {
			return;
		}
		m_Vol--;
	}
	void channel_Up() {
		if (m_Channel == maxVol) {
			return;
		}
		m_Channel++;
	}
	void channel_Down() {
		if (m_Channel == minVol) {
			return;
		}
		m_Channel--;
	}
	void show_All() {
		cout << "開關狀態 : " << (m_State == on ? "開" : "關") << endl;
		cout << "音量 : " << m_Vol << endl;
		cout << "頻道 : " << m_Channel << endl;
	}

};

class Remote {
private:
	TV* remote_TV;
public:
	Remote() {
		cout << "遙控器" << endl;
	}
	Remote(TV *remote_TV) {
		this->remote_TV = remote_TV;//將比如現實新同事代入"新同事"的身份的接入點
	}
	void remote_Switch_On_Off() {
		this->remote_TV->switch_On_Off();
	}
	void remote_Vol_Up() {
		this->remote_TV->vol_Up();
	}
	void remote_Vol_Down() {
		this->remote_TV->vol_Down();
	}
	void remote_Channel_Up() {
		this->remote_TV->channel_Up();
	}
	void remote_Channel_Down() {
		this->remote_TV->channel_Down();
	}
	void remote_Set_Channel(int remote_Channel) {
		if (remote_Channel >= TV::minChannel && remote_Channel <= TV::maxChannel) {
			//
			this->remote_TV->m_Channel = remote_Channel;
		}
		else {
			cout << "頻道設置不正確" << endl;
			return;
		}
	}
	void remote_Set_Vol(int remote_Vol) {
		if (remote_Vol >= TV::minVol && remote_Vol <= TV::maxVol) {
			this->remote_TV->m_Vol = remote_Vol;
		}
		else {
			cout << "音量設置不正確" << endl;
		}
	}
	void remote_Show_All() {
		this->remote_TV->show_All();
	}
};

int main() {
	TV tv1;
	Remote remote1(&tv1);
	cout << "電視機初始狀態 : " << endl;
	remote1.remote_Show_All();

	remote1.remote_Switch_On_Off();
	remote1.remote_Vol_Up();
	remote1.remote_Channel_Up();
	cout << "電視機狀態1 : " << endl;
	remote1.remote_Show_All();

	remote1.remote_Set_Channel(99);
	remote1.remote_Set_Vol(-1);
	remote1.remote_Set_Vol(10000);
	remote1.remote_Set_Vol(30);
	cout << "電視機狀態2 : " << endl;
	remote1.remote_Show_All();

	return 0;
}
