def left(i):
    return 2*i +1
def right(i):
    return 2*i+2
def parent(i):
    return int(i/2)

def heapify(arr,n,i):
    smallest=i
    l=left(i)
    r=right(i)
    if(l<n and arr[l]<arr[smallest]):
        smallest=l
    if(r<n and arr[r]<arr[smallest]):
        smallest=r
    if(i!=smallest):
        arr[i],arr[smallest]=arr[smallest],arr[i]
        heapify(arr,n,smallest)

def InsertHeap(arr,x):
    arr.append(x)
    i=int(len(arr)/2)-1
    while(i!=0 and arr[parent(i)]>arr[i]):
        arr[i],arr[parent(i)]=arr[parent(i)],arr[i]
        i=parent(i)
    return arr



def minHeap():
    for i in range(int(len(arr)/2)-1,-1,-1):
        print("heapyinh")
        heapify(arr,len(arr),i)
arr=[10,15,50,4,20]
minHeap()
print(arr)
print(InsertHeap(arr,0))
