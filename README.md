# Libserial 

A static library to read from serial port

------



##### To Install

```
sudo apt update
sudo apt install autogen autoconf build-essential cmake graphviz libboost-dev libgtest-dev libtool python-sip-dev doxygen
```

------



##### To Use with CMakeLists

```
add_subdirectory(libserial)
target_link_libraries(main libserial)
```

------



##### Developing

```
#include <SerialStream.h>

using namespace LibSerial ;

// Setup
SerialStream my_serial_stream("/dev/ttyUSB0");
my_serial_stream.SetBaudRate(BaudRate::BAUD_9600);
my_serial_stream.SetCharacterSize(CharacterSize::CHAR_SIZE_8);
my_serial_stream.SetParity(Parity::PARITY_NONE);
my_serial_stream.SetStopBits(StopBits::STOP_BITS_1) ;
my_serial_stream.SetFlowControl(FlowControl::FLOW_CONTROL_NONE);

// To Read
datatype variable;
my_serial_stream >> variable;

// To Write
datatype variable;
my_serial_stream << variable << std::endl;

/* By Block Size */
// To Read
const int BUFFER_SIZE = 256;
char input_buffer[BUFFER_SIZE];
my_serial_stream.read( input_buffer, BUFFER_SIZE );

// To Write
const int BUFFER_SIZE = 256;
char output_buffer[BUFFER_SIZE];

for( int i=0; i<BUFFER_SIZE; ++i )
{
    output_buffer[i] = i;
}

my_serial_stream.write( output_buffer, BUFFER_SIZE );


// Close
my_serial_stream.Close();
```