## Part 1: Procedure

Write the procedure for bubble sort, given `int list[3];`:

1. set `count` to `0`
2. set `swap` to `false`
3. if `list[count]` > `list[count + 1]`
	1. swap `list[count]` with `list[count + 1]`
	2. set `swap` to `true`
4. if `count` < `3`
	1. increment `count`
	2. goto 3
5. if `swap` is `false`
	1. stop
6. goto 1

## Part 2: Test

step | `list[0]` | `list[1]` | `list[2]` | `list[3]` | `list[4]` | `count` | `swap` 
-----|:-------:|:-------:|:--------:|:-------:|:-------:|:----:|:---:
1 | **9** | **7** | 2 | 6 | 1 | 0 | F
2 | 7 | **9** | **2** | 6 | 1 | 1 | T
3 | 7 | 2 | **9** | **6** | 1 | 2 | T
4 | 7 | 2 | 6 | **9** | **1** | 3 | T
5 | 7 | 2 | 6 | 1 | 9 | **4** | **T**
6 | **7** | **2** | 6 | 1 | 9 | 0 | F
7 | 2 | **7** | **6** | 1 | 9 | 1 | T
8 | 2 | 6 | **7** | **1** | 9 | 2 | T
9 | 2 | 6 | 1 | **7** | **9** | 3 | T
10 | 2 | 6 | 1 | 7 | 9 | **4** | **T**
11 | **2** | **6** | 1 | 7 | 9 | 0 | F
12 | 2 | **6** | **1** | 7 | 9 | 1 | F
13 | 2 | 1 | **6** | **7** | 9 | 2 | T
14 | 2 | 1 | 6 | **7** | **9** | 3 | T
15 | 2 | 1 | 6 | 7 | 9 | **4** | **T**
16 | **2** | **1** | 6 | 7 | 9 | 0 | F
17 | 1 | **2** | **6** | 7 | 9 | 1 | T
18 | 1 | 2 | **6** | **7** | 9 | 2 | T
19 | 1 | 2 | 6 | **7** | **9** | 3 | T
20 | 1 | 2 | 6 | 7 | 9 | **4** | **T**
21 | **1** | **2** | 6 | 7 | 9 | 0 | F
22 | 1 | **2** | **6** | 7 | 9 | 1 | F
23 | 1 | 2 | **6** | **7** | 9 | 2 | F
24 | 1 | 2 | 6 | **7** | **9** | 3 | F
25 | 1 | 2 | 6 | 7 | 9 | 4 | F

## Part 3: Improved Bubble Sort Procedure

1. set `n` to `3`
2. set `count` to `0`
3. if `list[count]` > `list[count + 1]`
	1. swap `list[count]` with `list[count + 1]`
4. if `count` < `n`
	1. increment `count`
	2. goto 3
5. decrement `n`
6. if `n` < `0`
	1. STOP
7. goto 2

## Part 4: Test Again

step | `list[0]` | `list[1]` | `list[2]` | `list[3]` | `list[4]` | `count` | `n` 
-----|:-------:|:-------:|:--------:|:-------:|:-------:|:----:|:---:
1 | 9 | 7 | 2 | 6 | 1 | 0 | 4
2 | 7 | 9 | 2 | 6 | 1 | 1 | 4
3 | 7 | 2 | 9 | 6 | 1 | 2 | 4
4 | 7 | 2 | 6 | 9 | 1 | 3 | 4
5 | 7 | 2 | 6 | 1 | 9 | 4 | 4
6 | 7 | 2 | 6 | 1 | 9 | 0 | 3
7 | 2 | 7 | 6 | 1 | 9 | 1 | 3
8 | 2 | 6 | 7 | 1 | 9 | 2 | 3
9 | 2 | 6 | 1 | 7 | 9 | 3 | 3
10 | 2 | 6 | 1 | 7 | 9 | 0 | 2
11 | 2 | 6 | 1 | 7 | 9 | 1 | 2
12 | 2 | 1 | 6 | 7 | 9 | 2 | 2
13 | 2 | 1 | 6 | 7 | 9 | 0 | 1
14 | 1 | 2 | 6 | 7 | 9 | 1 | 1
15 | 1 | 2 | 6 | 7 | 9 | 0 | 0
16 | 1 | 2 | 6 | 7 | 9 | 0 | -1
%%
## Misc

**Initial Bubble Sort**
```cpp
int list[size]; // initialize array
bool swap;
do {
	// reset swap
	swap = false;
	// iterate over array
	for (int i=0; i < sizeof(list) - 2; ++i) {
		if (list[i] > list[i + 1]) {
		    // swap
			int tmp = list[i + 1];
			list[i + 1] = list[i];
			list[i] = tmp;
			swap = true; // indicates array isn't sorted
		}
	}
} while (swap); // if isn't sorted, continue
```
**Improved Bubble Sort**
```python
a = [9,7,2,6,1]
n = len(a)-1
while True:
	for i in range(n):
		if a[i] > a[i+1]:
			a[i], a[i+1] = a[i+1], a[i]
	n-=1
	if n < 0:
		break
```
%%