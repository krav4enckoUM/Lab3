#include "rccregisters.hpp"
#include "gpiocregisters.hpp"
#include <iostream>
int main()
{  
  RCC::CR::HSION::On::Set(); 
  while(!RCC::CR::HSIRDY::Ready::IsSet())
  {
  }
  
  RCC::CFGR::SW::Hsi::IsSet();
  
  while(!RCC::CFGR::SWS::Hsi::IsSet());
  {
  }
  
  RCC::CR::HSEON::Off::Set();  
  RCC::AHB1ENR::GPIOCEN::Enable::Set();
  GPIOC::MODER::MODER5::Output::Set();

  for(;;)
  {
    for (int i= 0; i < 1000000 ; i ++)
    {
    }
    
    GPIOC::ODR::ODR5::High::Set() ;
  
    for (int i= 0; i < 1000000 ; i ++)
    {
    }
    GPIOC::ODR::ODR5::Low::Set() ;
  }
  return 1 ;
}
