先来了解一下什么是查找，
额，好吧，这没什么可了解的，
就是查找数组中的某个元素的位置或是否存在。
就这，没了。直接了解查找算法吧。

## 线性查找
线性查找与二分查找有些差别。
数组内元素可以是混乱无序的，即没有按顺序储存。这方法很简单，就是从首元素开始，依此向后查找，比较。仅此而已。运用循环，依次对比。
看代码吧。

```c
#include <stdio.h>
int main(void)
{
	int arr[] = { 5,4,6,8,7,9,10,2,3,1 };
	int len = sizeof(arr) / sizeof(arr[0]);//计算数组的元素个数
	int i;
	int n;
	scanf("%d", &n);//输入要查找的元素

	for (i = 0; i < len; i++)
	{
		if (arr[i] == n)
		{
			printf("%d的下标是%d\n", n, i);
			break;//找到后就直接跳出循环
		}
	}

	if (i == len)//因为如果数组元素全部遍历一遍后，都没有i++等于len后，便跳出循环再判断说不存在。
		printf("Don't have number %d\n", n);

	return 0;

}

```

线性查找非常简单但，要是数组元素较大，就比较麻烦，毕竟要一个个遍历过去时间复杂度为n。




## 二分查找
来看看二分查找，就是高中数学学到过的二分法，原理相当简单。但是它只能查找已经排序好的数组，与线性查找相比，有些局限性。
通过比较数组中间数据与目标数据的大小，来判断是在中间数据的左边还是右边，瞬间缩小一半的运算量。再按照这种继续比较，直到找到或找不到为止。


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
		printf("%d的下标是%d\n", n, mid);
	else
		printf("DON't have number %d\n", n);
	return 0;

}
/*int i = 1;
```
看张图吧，方便理解与记忆。
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210116235924470.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MjE5OTEwOQ==,size_16,color_FFFFFF,t_70#pic_center)
看代码中的，中间元素是5，在5的右边，再把不需要的元素移出比较范围，再，重新设置中间元素，进行比较。
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210117000540490.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MjE5OTEwOQ==,size_16,color_FFFFFF,t_70#pic_center)
再拿8进行比较，在8左边。重新规划范围。
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210117001201226.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MjE5OTEwOQ==,size_16,color_FFFFFF,t_70#pic_center)
7比6大，则在6右边，继续比较。
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210117001458877.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MjE5OTEwOQ==,size_16,color_FFFFFF,t_70#pic_center)
此时，left==right,跟据while循环条件，依旧可以进入循换,但arr[mid]==7,说明已经找到那个元素，会break;跳出循环，再判断条件满足left<=right，说明依旧成立，就输出。
否则，如果目标元素是11，则一直会是中间元素的右边。
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210117002611393.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MjE5OTEwOQ==,size_16,color_FFFFFF,t_70#pic_center)
再left=MID+1就是10,此时，left==right，循环还没结束，这一次，mid等于10还是比11小，left=10+1,而此时，left>right，不符合条件，循环结束，再判断，不符合条件，就进入else，，说明，11不在数组内。
我第一次写二分查找时，，没有写

```c
left = mid+1;
right = mid-1;

```
而是写

```c
right = mid;
left = mid;
```
本以为差不多，额，事实上确实差不多，不过当目标数据不在数组内时，要提前判断。如果直接以上面代码的形式，改条件，就会造成，left一直是9,right一直是10，mid也一直是9，无法跳出循环，造成这样的死循环局面。
当写二分查找时一定要切记。
这两个查护，目前就这些。
如有问题，烦请大佬指点一二。
谢谢观看。