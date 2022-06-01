#include <windows.h>


//---------- Step 02 ----------		>>> 窗口處理函數(自定義,用於處理消息)  <<<
//窗口處理函數(自定義,用於處理消息)
LRESULT CALLBACK WndProc(
	HWND hWnd, // 窗口句柄
	UINT msgID, // 消息ID
	WPARAM wParam, //
	LPARAM lParam) { //

	return DefWindowProc(hWnd, msgID, wParam, lParam);
	// DefWindowProc 微軟提供的系統調用函數
}

//---------- Step 02 ----------		>>> 窗口處理函數(自定義,用於處理消息)  <<<

//---------- Step 01 ----------		>>> 入口函數 <<<
//入口函數
int CALLBACK WinMain(
	HINSTANCE hIns, // 當前程序實例句柄
	HINSTANCE hPreIns, // 已廢棄不用,但佔位置,必須標識出來
	LPSTR lpCmdLine,  // 命令行參數
	int nCmdShow) {// 窗口的顯示方式

// ---------- Step 03 ---------- >>> 注冊窗口類(向系統內核寫入數據) <<<
	WNDCLASS wc = { 0 }; // 結構體,首先 先賦0,之後再對其內的 十多成員依次賦值
	wc.cbClsExtra = 0; // 開緩衝區用的成員,比如賦100,即申請100bytes緩衝區
					   //現在先賦0,不申請緩衝區
	wc.cbWndExtra = 0; // 都是申請緩衝區,但是申請另一種緩衝區
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); // 背景色+1白,+3黑
	wc.hCursor = NULL; // 光標,NULL代表默認光標
	wc.hIcon = NULL; // 左上角圖標,NULL代表默認圖標
	wc.hInstance = hIns; // WinMain第一個參數,即當前程序實例句柄
	wc.lpfnWndProc = WndProc; // 窗口處理函數的名字,基本定理「函數名即函數地址」
	wc.lpszClassName = "Main"; // 窗口類名稱(字符串)
	wc.lpszMenuName = NULL; // 不要菜單,別的地方NULL是default,這裏是不要
	wc.style = CS_HREDRAW | CS_VREDRAW; // 只要窗口寬高一有改變,
										//??即時重畫成新的寬高??
	RegisterClass(&wc); // RegisterClass(&wc)
						//將以上賦值全部寫入操作系統內核
	// ---------- Step 03 ---------- >>> 注冊窗口類(向系統內核寫入數據) <<<

	// ---------- Step 04 ---------- >>> 在內存中創建窗口 <<<
	//					>>> 以下為創建一塊內存空間,在裏面存入窗口的各項數據 <<<  
	HWND hWnd = CreateWindowEx(	// 返回的是創建窗口的句柄
		0, // 不知有何優勝之處的加強版,僅在前面加了一項無用參數,"0" 它即可
		"Main", // 窗口類的名字,見窗口類wc.lpszClassName
		"標題欄信息", // 標題欄信息
		WS_OVERLAPPEDWINDOW, // 窗口基本風格
							 // -----P6,06:16-----
							 // -----P6,10:33-----
		100, 100, // 窗口在什麼地方出現
		500, 500, // 窗口的 寬、高
		NULL, // 本窗口的父窗口,沒有,因為這裏本窗口就是原窗口
		NULL, // 菜單,不要菜單,NULL
		hIns,  // 當前程序實例實例句柄
			   // WinMain的第一個參數
		NULL); // 無用參數,但佔位置
// ---------- Step 04 ---------- >>> 在內存中創建窗口 <<<
// ---------- Step 05 ---------- >>> 顯示窗口 <<<
	ShowWindow( // 調用函數,按照之前的參數,在螢幕上畫窗口的圖像
		hWnd, // CreateWindow中創建窗口的句柄
			  //hWnd把以上的參數放到ShowWindow中顯示
		SW_SHOW); //「原樣繪製」,窗口於100,100的位置,500,500的寬高原樣繪製
// ---------- Step 05 ---------- >>> 顯示窗口 <<<
// ---------- Step 06 ---------- >>> 刷新窗口 <<<
	UpdateWindow(hWnd); // 不調也無所謂,但微軟建議調
						// 此函數把窗口再畫一次,叫做刷新窗口
	// ---------- Step 06 ---------- >>> 刷新窗口 <<<
	// ---------- Step 07 ---------- >>> 消息循環 <<<
	//								 >>>循環獲得消息<<< 
	MSG nMsg = { 0 };//這是一個結構體
	while (GetMessage // --- Step 07 (1) --- >> 從某處抓消息(未講) << 
	(&nMsg, // 把GetMessage抓到的消息,存到結構體nMsg中
		NULL,
		0,
		0) // NULL,0,0有何用處未講
		) {


		TranslateMessage(&nMsg);// --- Step 07 (2) --- >> 抓到消息然後處理消息 <<
		DispatchMessage(&nMsg);// --- Step 07 (3) --- >> 派發消息,把消息傳給派發消息的函數 <<
		// LRESULT CALLBACK WndProc為窗口處理函數,把消息派發給它

	}
	// ---------- Step 07 ---------- >>> 消息循環 <<<

	return 0;
}
//---------- Step 01
