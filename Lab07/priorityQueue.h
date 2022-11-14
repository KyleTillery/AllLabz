#include <string>

// This class is exported from the LinkedList.dll
class  priorityQueue {
public:

	priorityQueue();

	/** Returns true  if list is empty, otherwise false */
	virtual bool isEmpty() const ;
	/** Adds a value to the LinkedList.  Adds the value to the end of the List.  Return true if able to, otherwise false */
	virtual bool insert(int val) = 0;
	/** Remove a value to the LinkedList.  Return true if able to, otherwise false.
	Will only remove one entry if there are multiple entries with the same value */
	virtual bool DeQueue() = 0;
	/** Remove  all elements from LinkedList */
        /** Generates a string of the contents of the LinkedList, and lists them in order.  */
	virtual std::string toString() const = 0;

protected:
	int m_count;

};

class HeapBased : public priorityQueue
{
public:
	HeapBased();
	/** Adds a value to the LinkedList.  Adds the value to the end of the List. Return true if able to, otherwise false */
	bool insert(int val) override;
	/** Remove a value to the LinkedList.  Return true if able to, otherwise false.
	Will only remove one entry if there are multiple entries with the same value */
	bool DeQueue() override;
	/** Remove  all elements from LinkedList */
	virtual ~HeapBased() ;
	/** Generates a string of the contents of the LinkedList, and lists them in order.  */
	std::string toString() const override;
	bool isEmpty();
protected:
	int m_values[5000] = {0};//maybe set m_values500[500], m_values1000[1000], etc and just copy paste the cpp code to use the different
	//m_values#[#] arrays

};

class ArrayBased : public priorityQueue
{
public:
	void othersort();
	ArrayBased();
	/** Adds a value to the LinkedList. Adds the value to the end of the List. Return true if able to, otherwise false */
	bool insert(int val) override;
	/** Remove a value to the LinkedList.  Return true if able to, otherwise false.
	Will only remove one entry if there are multiple entries with the same value */
	bool DeQueue()  override;
	/** Remove  all elements from LinkedList */
	virtual ~ArrayBased();
	/** Generates a string of the contents of the LinkedList, and lists them in order.  */
	std::string toString() const override;
	bool isEmpty();

private:
	int m_valuesother[5000] = {0};
	
};