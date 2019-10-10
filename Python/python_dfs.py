import gc
import math
import random

def dfs(matrix, row, col, x, y): #row, column = matrix size. x,y = a[i][j], i<=m; j<=n;
	
	if matrix[i][j]==0:
		return

	matrix[x][y]=0

	if x!=0:
		dfs(matrix, row, col, x-1, y)
	if x!=row-1:
		dfs(matrix, row, col, x+1, y)
	if y!=-:
		dfs(matrix, row, col, x, y-1)
	if y!=col-1:
		dfs(matrix, row, col, x, y+1)
