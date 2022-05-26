#include <windows.h>

//窗口處理函數(自定義,用於處理消息)
LRESULT CALLBACK WndProc(HWND hWnd, UINT msgID, WPARAM wParam, LPARAM lParam) {
	return DefWindowProc(hWnd, msgID, wParam, lParam);
}

//入口函數  //第一步
int CALLBACK WinMain(HINSTANCE hIns, HINSTANCE hPreIns, LPSTR lpCmdLine, int nCmdShow) {
	//注冊窗口類(向系統內核寫入數據)    //第二步
	WNDCLASS wc = { 0 };
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);//背景色+1白,+3黑
	wc.hCursor = NULL;//光標,NULL代表默認光標
	wc.hIcon = NULL;//左上角圖標,NULL代表默認圖標
	wc.hInstance = hIns;
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = "Main";//窗口類名稱(字符串)
	wc.lpszMenuName = NULL;//不要菜單
	wc.style = CS_HREDRAW | CS_VREDRAW;//只要窗口寬高一有改變即還原?
	RegisterClass(&wc);//RegisterClass(&xxx)將以上賦值全部寫入操作系統內核

	//第三步
	//以下為創建一塊內存空間,在裏面存入窗口的各項數據  //名為 : 在內存中創建窗口
	HWND hWnd = CreateWindow("Main", "標題欄信息", WS_OVERLAPPEDWINDOW, 100, 100, 500, 500, NULL, NULL, hIns, NULL);
	//第一參,第二參,窗口基本風格,在什麼坐標創建窗口,窗口寬與高,無副窗口,無菜單,WinMain第一個參數,最後一個是無意義參數

	
//顯示窗口   //第四步 把窗口顥示出來
	ShowWindow(hWnd, SW_SHOW);
	//hWnd把以上的參數放到ShowWindow中顥示
	//SW_SHOW : 窗口於100,100的位置,500,500的寬高原樣繪製
	UpdateWindow(hWnd);//不調也無所謂,此函數把窗口再畫一次,叫做刷新窗口

	//第五步 消息循環
	//循環獲得消息 //分三個小部1)抓消息2)
	MSG nMsg = { 0 };//這是一個結構體
	while (GetMessage(&nMsg, NULL, 0, 0)) { //從某處抓消息(未講),保存到nMsg結構體的第一個函數中
	//NULL,0,0有何用處未講

		//第六步 處理消息  用最上面 LRESULT CALLBACK WndProc 函數
		TranslateMessage(&nMsg);//抓到消息然後處理消息
		DispatchMessage(&nMsg);//派發消息,把消息傳給派發消息的函數
		//LRESULT CALLBACK WndProc為窗口處理函數,把消息派發給它

	}

	return 0;
}
