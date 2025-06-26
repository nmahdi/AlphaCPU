#ifndef CPU_H
#define CPU_H

#include "MyMemory.h"

class CPU 
{
	friend class Tsar;
	friend class Trinity;
	friend class LittleBoy;
	friend class Fatman;
	friend class Fallout;
	friend class Fission;
	//friend class Fusion
	
	private:
		Register<int> TSAR_REGISTER;
		Register<long> TRINITY_REGISTER;
		Register<float> LITTLEBOY_REGISTER;
		Register<double> FATMAN_REGISTER;
		Register<bool> FALLOUT_REGISTER;
		Register<char> FISSION_REGISTER;
		//Register<std::string> FUSION_REGISTER;

	public:
		CPU() {}
		
		template<class T, class U>
		void PUSH(Memory<T> &memory, int address, U value)
		{
			memory.write(address, value);	
		}
		
		template<class T>
		void POP(Memory<T> &memory, int address)
		{
			memory.remove(address);
		}
		
		template<class T>
		int MOV(Register<T> &reg, Memory<T> &memory, int mAddress)
		{
			int rAddress = reg.newAddress();
			reg.write(rAddress, memory.read(mAddress));
			return rAddress;
		}
		
		template<class T>
		void ADD(Register<T> &reg, Memory<T> &memory, int memFirst, int memSecond)
		{
			preformOperation(reg, memory, memFirst, memSecond, 0);
		}
		
		template<class T>
		void SUB(Register<T> &reg, Memory<T> &memory, int memFirst, int memSecond)
		{
			preformOperation(reg, memory, memFirst, memSecond, 1);	
		} 
		
		template<class T>
		void MUL(Register<T> &reg, Memory<T> &memory, int memFirst, int memSecond)
		{
			preformOperation(reg, memory, memFirst, memSecond, 2);	
		}
		
		template<class T>
		void DIV(Register<T> &reg, Memory<T> &memory, int memFirst, int memSecond)
		{
			preformOperation(reg, memory, memFirst, memSecond, 3);	
		}
		
		template<class T>
		void CMP(Register<T> &reg, Memory<T> &memory, int memFirst, int memSecond)
		{
			reg.setFlag(memory.read(memFirst)-memory.read(memSecond));	
		}
		
		/*
			Moves the two provided address' using the MOV() function,
			then calculates the operation using the provided register,
			then over-writes the first object's memory.
		*/ 
		template<class T>
		void preformOperation(Register<T> &reg, Memory<T> &memory, int memFirst, int memSecond, int operation)
		{
			int regFirst = MOV(reg, memory, memFirst);
			int regSecond = MOV(reg, memory, memSecond);
							
			switch(operation)
			{
				case 0: {	// ADDITION
					reg.write(regFirst, reg.read(regFirst) + reg.read(regSecond));
					break;
				}
				case 1: {	// SUBTRACTION
					reg.write(regFirst, reg.read(regFirst) - reg.read(regSecond));
					break;
				}
				case 2: {	// MULTIPLCATION
					reg.write(regFirst, reg.read(regFirst) * reg.read(regSecond));
					break;
				}
				case 3: {	// DIVISION
					reg.write(regFirst, reg.read(regFirst) / reg.read(regSecond));
					break;
				}
			}
					
			reg.remove(regSecond);
			memory.write(memFirst, reg.read(regFirst));
			reg.remove(regFirst);	
		}
};

static CPU myCPU;

#endif 
