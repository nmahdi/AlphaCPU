#ifndef MEMORY_H
#define MEMORY_H

#include <map>

template<class T>
class Memory
{
	private:
		std::map<int, T> data;

	public:
		Memory() {}
		
		T read(int address) const 
		{ 
			return data.at(address); 
		}
		
		void write(int address, T object)
		{ 
			data[address] = object;
		}
		
		void remove(int address)
		{
			data.erase(address);
		}
		
		/*
			Looks for the first empty spot in memory and returns it.
		*/
		int newAddress() 
		{ 
			int lastAddress = 0;
			if(data.size() > 0)
			{
				for(typename std::map<int, T>::iterator it = data.begin(); it != data.end(); it++)
				{	
					if(it->first != lastAddress)
						return lastAddress;
					
					lastAddress++;
				}
			}
			return lastAddress;
		}
		
		int size() const { return data.size(); }
};

template<class T>
class Register : public Memory<T>
{
	private:
		int flag;
	public:
		Register() {}
		
		void setFlag(int flag)
		{
			this->flag = flag;
		}
		
		int getFlag()
		{
			return flag;
		}
		
};






#endif
