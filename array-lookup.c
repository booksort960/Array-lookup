�����˽�һ��ʲô�ǲ��ң�
��ðɣ���ûʲô���˽�ģ�
���ǲ��������е�ĳ��Ԫ�ص�λ�û��Ƿ���ڡ�
���⣬û�ˡ�ֱ���˽�����㷨�ɡ�

## ���Բ���
���Բ�������ֲ�����Щ���
������Ԫ�ؿ����ǻ�������ģ���û�а�˳�򴢴档�ⷽ���ܼ򵥣����Ǵ���Ԫ�ؿ�ʼ�����������ң��Ƚϡ����˶��ѡ�����ѭ�������ζԱȡ�
������ɡ�

```c
#include <stdio.h>
int main(void)
{
	int arr[] = { 5,4,6,8,7,9,10,2,3,1 };
	int len = sizeof(arr) / sizeof(arr[0]);//���������Ԫ�ظ���
	int i;
	int n;
	scanf("%d", &n);//����Ҫ���ҵ�Ԫ��

	for (i = 0; i < len; i++)
	{
		if (arr[i] == n)
		{
			printf("%d���±���%d\n", n, i);
			break;//�ҵ����ֱ������ѭ��
		}
	}

	if (i == len)//��Ϊ�������Ԫ��ȫ������һ��󣬶�û��i++����len�󣬱�����ѭ�����ж�˵�����ڡ�
		printf("Don't have number %d\n", n);

	return 0;

}

```

���Բ��ҷǳ��򵥵���Ҫ������Ԫ�ؽϴ󣬾ͱȽ��鷳���Ͼ�Ҫһ����������ȥʱ�临�Ӷ�Ϊn��




## ���ֲ���
���������ֲ��ң����Ǹ�����ѧѧ�����Ķ��ַ���ԭ���൱�򵥡�������ֻ�ܲ����Ѿ�����õ����飬�����Բ�����ȣ���Щ�����ԡ�
ͨ���Ƚ������м�������Ŀ�����ݵĴ�С�����ж������м����ݵ���߻����ұߣ�˲����Сһ������������ٰ������ּ����Ƚϣ�ֱ���ҵ����Ҳ���Ϊֹ��


```c
#include <stdio.h>
int main(void)
{
	int n;
	scanf("%d", &n);
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int left = 0;
	int right = len - 1;
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (arr[mid] > n)
		{
			right = mid - 1;
		}
		else if (arr[mid] < n)
		{
			left = mid + 1;
		}
		else
		{
			break;
		}
	}
	if (left <= right)
		printf("%d���±���%d\n", n, mid);
	else
		printf("DON't have number %d\n", n);
	return 0;

}
/*int i = 1;
```
����ͼ�ɣ������������䡣
![���������ͼƬ����](https://img-blog.csdnimg.cn/20210116235924470.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MjE5OTEwOQ==,size_16,color_FFFFFF,t_70#pic_center)
�������еģ��м�Ԫ����5����5���ұߣ��ٰѲ���Ҫ��Ԫ���Ƴ��ȽϷ�Χ���٣����������м�Ԫ�أ����бȽϡ�
![���������ͼƬ����](https://img-blog.csdnimg.cn/20210117000540490.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MjE5OTEwOQ==,size_16,color_FFFFFF,t_70#pic_center)
����8���бȽϣ���8��ߡ����¹滮��Χ��
![���������ͼƬ����](https://img-blog.csdnimg.cn/20210117001201226.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MjE5OTEwOQ==,size_16,color_FFFFFF,t_70#pic_center)
7��6������6�ұߣ������Ƚϡ�
![���������ͼƬ����](https://img-blog.csdnimg.cn/20210117001458877.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MjE5OTEwOQ==,size_16,color_FFFFFF,t_70#pic_center)
��ʱ��left==right,����whileѭ�����������ɿ��Խ���ѭ��,��arr[mid]==7,˵���Ѿ��ҵ��Ǹ�Ԫ�أ���break;����ѭ�������ж���������left<=right��˵�����ɳ������������
�������Ŀ��Ԫ����11����һֱ�����м�Ԫ�ص��ұߡ�
![���������ͼƬ����](https://img-blog.csdnimg.cn/20210117002611393.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MjE5OTEwOQ==,size_16,color_FFFFFF,t_70#pic_center)
��left=MID+1����10,��ʱ��left==right��ѭ����û��������һ�Σ�mid����10���Ǳ�11С��left=10+1,����ʱ��left>right��������������ѭ�����������жϣ��������������ͽ���else����˵����11���������ڡ�
�ҵ�һ��д���ֲ���ʱ����û��д

```c
left = mid+1;
right = mid-1;

```
����д

```c
right = mid;
left = mid;
```
����Ϊ��࣬���ʵ��ȷʵ��࣬������Ŀ�����ݲ���������ʱ��Ҫ��ǰ�жϡ����ֱ��������������ʽ�����������ͻ���ɣ�leftһֱ��9,rightһֱ��10��midҲһֱ��9���޷�����ѭ���������������ѭ�����档
��д���ֲ���ʱһ��Ҫ�мǡ�
�������黤��Ŀǰ����Щ��
�������⣬�������ָ��һ����
лл�ۿ���