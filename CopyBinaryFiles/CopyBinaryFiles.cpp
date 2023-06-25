#include <fstream>
#include <iostream>
#include <cstring>

constexpr unsigned int max_buffer = 512;

void copy_binary(const char* source, const char* target);
std::streamoff file_size(const char* input);
int main(const int argc, char* argv[])
{
    

    if(argc < 3)
    {
        std::cout << "Use: CopyBinaryFiles.exe <source_file> <target_file>";
    }
    else
    {
       copy_binary(argv[1], argv[2]);
    }
    return 0;
}

void copy_binary(const char* source, const char* target)
{
    const std::streamoff source_size = file_size(source);

    std::ifstream input;
    input.open(source, std::ios::binary | std::ios::in);

    std::ofstream output {target, std::ios::binary | std::ios::out};

    char buffer[max_buffer];
    std::cout << "Copying " << source;
    // Small File we process full file
    if(source_size < max_buffer)
    {
        if(!input.read(buffer, source_size))
        {
            throw std::runtime_error("Error in reading operation.");
        }

        if(!output.write(buffer, source_size))
        {
            throw std::runtime_error("Error in writing operation.");
        }
    }
    else
    {
        const std::streamoff num_chunks = source_size / max_buffer;
        const std::streamoff remaining = source_size % max_buffer;
        int oldprogress{};
        // Big files we read in chunks
        for(int i=0; i < num_chunks; i++)
        {
            if(!input.read(buffer, max_buffer))
            {
                throw std::runtime_error("Error in reading operation.");  
            }

            if(!output.write(buffer, max_buffer))
            {
                throw std::runtime_error("Error in writing operation.");
            }

            const int progress = static_cast<int>((10 * static_cast<float>(i) / num_chunks));
            if(progress != oldprogress)
            {
                std::cout << ".";
            }
            oldprogress = progress;
        
        }

        // Process remaining bytes
        if(remaining > 0)
        {
            memset(buffer, '\0', max_buffer);
            if(!input.read(buffer, remaining))
            {
                throw std::runtime_error("Error in reading operation.");
            }

            if(!output.write(buffer, remaining))
            {
                throw std::runtime_error("Error in writing operation.");
            }
            std::cout << ".";
        }
    }
    std::cout << " Done!." << std::endl;
    input.close();
    output.close();
   
}

std::streamoff file_size(const char* input)
{
    std::ifstream input_stream;
    input_stream.open(input, std::ios::binary | std::ios::in);
    input_stream.seekg(0, std::ios::end);
    const std::streamoff size = input_stream.tellg();   
    input_stream.close();

    return size;
}
