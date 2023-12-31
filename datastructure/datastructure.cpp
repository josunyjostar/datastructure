﻿#include <iostream>
using namespace std;

#include "./HashTable/HashTable.h"
#include "./Heap/MyHeap.h"
#include "./List/List.h"

int main()
{
    //HashTable<const char*,const char*> hashTable;
        
    //hashTable.Add("test1", "1번");
    //hashTable.Add("test1", "2번");
    //hashTable.Add("test1", "3번");
    //hashTable.Add("test1", "4번");
    //
    //hashTable.Delete("test1", "3번");
    //hashTable.Print("test1");

    //const int arr[] = { 1,3,4,5 };
    //for (auto& el : arr) {
    //    cout << el << endl;
    //}

    //Heap<int> h;

    //for (auto i : { 2, 8, 5, 3, 2, 1, 9, 3, 7, 2, 4 })
    //{
    //    h.Push(i);
    //    h.Print();
    //}

    //while (!h.IsEmpty())
    //{
    //    cout << h.Top() << " ";
    //    h.Pop();
    //    h.Print();
    //}
    
    List<int> list;
    list.Insert(1);
    list.Insert(2);
    list.Insert(3);

    list.Print();

    std::cout << "Hello World!\n";
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
