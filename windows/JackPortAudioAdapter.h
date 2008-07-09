/*
Copyright (C) 2008 Grame

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

*/

#ifndef __JackPortAudioAdapter__
#define __JackPortAudioAdapter__

#include "JackAudioAdapter.h"
#include "portaudio.h"
#include "jslist.h"

namespace Jack
{

   	class JackPortAudioAdapter : public JackAudioAdapterInterface
	{
    
		private:
        
            PaStream* fStream;
            PaDeviceIndex fInputDevice;
            PaDeviceIndex fOutputDevice;
            
            static int Render(const void* inputBuffer, void* outputBuffer,
                            unsigned long framesPerBuffer,
                            const PaStreamCallbackTimeInfo* timeInfo,
                            PaStreamCallbackFlags statusFlags,
                            void* userData);
       
		public:
        
			JackPortAudioAdapter(int input, int output, jack_nframes_t buffer_size, jack_nframes_t sample_rate, const JSList* params)
                :JackAudioAdapterInterface(input, output, buffer_size, sample_rate)
            {}
			~JackPortAudioAdapter()
            {}
            
            int Open();
            int Close();
            
           int SetBufferSize(jack_nframes_t buffer_size);
            
   	};
}

#endif
