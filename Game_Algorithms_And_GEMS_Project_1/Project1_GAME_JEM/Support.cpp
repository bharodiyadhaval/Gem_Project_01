#include "Support.h"
#include <time.h>
#include <Windows.h>
#include <chrono>
#include <psapi.h>


clock_t startTime;

void StartPerformance(sPerfData &data)
{

	startTime = clock();

	// Clear the performace data
	data.elapsedCallTime_ms = 0.0f;
	data.memoryUsageBytes_min = 0.0f;
	data.memoryUsageBytes_max = 0.0f;
	data.memoryUsageBytes_avg = 0.0f;

	HANDLE hProcess;
	PROCESS_MEMORY_COUNTERS pmc;

	hProcess = GetCurrentProcess();
	if (NULL == hProcess)
		return;

	if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc)))
	{
		data.memoryUsageBytes_min = pmc.WorkingSetSize;
		data.memoryUsageBytes_max = pmc.WorkingSetSize;
		data.memoryUsageBytes_avg = pmc.WorkingSetSize;
	}
	else
	{
		printf("There was an error asserting the performance data!\n");
	}

}



void EndPerformanceData(sPerfData &data)
{
	// Update the elapsed time
	data.elapsedCallTime_ms = ((float)(clock() - startTime) / CLOCKS_PER_SEC) * 1000.0f;

	// Updated performance data
	SIZE_T memMin = data.memoryUsageBytes_min;
	SIZE_T memMax = data.memoryUsageBytes_max;

	HANDLE hProcess;
	PROCESS_MEMORY_COUNTERS pmc;

	hProcess = GetCurrentProcess();
	if (NULL == hProcess)
		return;

	if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc)))
	{
		if (memMin > pmc.WorkingSetSize)
			data.memoryUsageBytes_min = pmc.WorkingSetSize;
		if (memMax < pmc.WorkingSetSize)
			data.memoryUsageBytes_max = pmc.WorkingSetSize;
		data.memoryUsageBytes_avg = (data.memoryUsageBytes_min + data.memoryUsageBytes_max) / 2.0f;
	}
	else
	{
		printf("There was an error asserting the performance data!\n");
	}
}