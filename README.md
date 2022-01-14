<hr/>  

<h3 align="center">🚀 42 Philosohpers 🚀</h3>  
<hr/>  

## ✔ 간단한 프로젝트 설명
> 쓰레드 문제로 유명한 문제 중 하나인 '철학자 문제'를 만든다.  
> n명의 철학자에게는 n개의 포크가 주어진다.
> 각 철학자는 양손에 포크 즉, 두개의 포크를 쥐어야만 식사가 가능하다.  
> 다만, 이때 철학자들에게는 생존시간, 먹는시간, 자는시간이 존재한다. 생존시간은 마지막으로 먹는 시간을 시작지점으로 카운트 한다. 생존시간을 넘긴 철학자는 죽지만 다른 철학자들은 누가 죽는지 알 수 없어야 한다.

<br/>  

## ✔ 출력 state
* timestamp X has taken a fork
* timestamp X is eating
* timestamp X is sleeping
* timestamp X is thinking
* timestamp X died

<br/>  

## ✔ 실행 화면
> ./philo 철학자수 생존시간 먹는시간 자는시간 [최소 먹는 횟수]  

![image](https://user-images.githubusercontent.com/69746967/149469987-adb436c6-729f-491b-ab3b-33544d444c12.png)


<br/>  

## ✔ 개선사항
1. leak은 안나왔지만... allocation된 요소들은 free 시켜줄 것
2. 철학자들의 thread들이 모두 종료하는지 확인할 것. 이 부분은 좀 더 고민 중. 그럴 필요가 있는가?(detach가 아닌 join으로?)

<br/>  

