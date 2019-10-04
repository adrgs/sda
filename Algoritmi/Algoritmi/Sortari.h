#pragma once

template <typename T>
void ControlSort(T *arr, int n);
template <typename T>
void BubbleSort(T *arr, int n);
template <typename T>
void SelectionSort(T *arr, int n);
template <typename T>
void InsertionSort(T *arr, int n);

int* GenerateRandomArray(int n);
void UnitTests(int n);