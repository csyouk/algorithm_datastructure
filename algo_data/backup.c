//for (int i = 0; i < WIDTH; i++)
//{
//	for (int j = 0; j < HEIGHT; j++)
//	{
//		if (i == 0 || j == 0 || i == WIDTH - 1 || j == HEIGHT - 1)
//		{
//			if (canvas[i][j]) { cnt++; }
//			continue;
//		}
//
//		if (canvas[i][j])
//		{
//			int p = 0;
//			for (int k = -1; k < 2; k++)
//			{
//				for (int l = -1; l < 2; l++)
//				{
//					p += canvas[i + k][j + l];
//				}
//			}
//			if ((p == 8) &&
//				(canvas[i - 1][j - 1] == 0 ||
//				canvas[i - 1][j + 1] == 0 ||
//				canvas[i + 1][j - 1] == 0 ||
//				canvas[i + 1][j + 1] == 0))
//			{
//				continue;
//			}
//			if (p != 9)
//			{
//				cnt++;
//			}
//		}
//	}
//}

//
//backup = total_budget;
//for (int j = 0; j < i; j++)
//{
//	total_budget -= budget[j];
//}
//ub = total_budget / (n - i);
//for (int j = i; j < n; j++)
//{
//	int b;
//	if (ub < budget[j])
//	{
//		b = ub;
//	}
//	else
//	{
//		b = budget[j];
//	}
//	total_budget -= b;
//}
//
//for (int i = 0; i < n; i++)
//{
//	if (budget[i] > ub)
//}
//
//if (tmp_b > total_budget)
//{
//	tmp_b = total_budget;
//	max_ub = ub;
//}
//else
//{
//	break;
//};
//total_budget = backup;
//i++;
//if (n == i) break;