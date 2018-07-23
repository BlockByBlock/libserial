#include "SerialStream.h"
#include <iostream>
#include <string>

using namespace LibSerial;

int main(int argc, char** argv)
{
    SerialStream my_serial_stream("/dev/ttyUSB0");
    my_serial_stream.SetBaudRate(BaudRate::BAUD_9600);
    my_serial_stream.SetCharacterSize(CharacterSize::CHAR_SIZE_8);
    my_serial_stream.SetParity(Parity::PARITY_NONE);
    my_serial_stream.SetStopBits(StopBits::STOP_BITS_1) ;
    my_serial_stream.SetFlowControl(FlowControl::FLOW_CONTROL_NONE);

    std::string rline;
    my_serial_stream >> rline;
    std::cout << rline << std::endl;

    my_serial_stream.Close();

    return 0;
}
