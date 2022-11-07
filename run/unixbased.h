#ifndef UNIXBASED_H
#define UNIXBASED_H
#ifndef _WIN32
#include <iostream>
#include <fstream>
#include <sstream>
#include <unistd.h>
using namespace std;

class Command {
    public:
        Command() {
            exit_code_ = -1;
        }

        int GetExitCode() { return exit_code_;}

        string GetStdOutStr() {return stdout_str_;}

        string GetStdErrStr() {return stderr_str_;}

        int Run(const char* cmd) {
            return Run(string(cmd));
        }

        /**
         * @brief run a given command
         * 
         * @param cmd: command string
         * @return int: the exit code of running the command
         */
        int Run(string cmd) {

            // create temp files
            char tmp_dir[] = "/tmp/stdir.XXXXXX";
            mkdtemp(tmp_dir);
            string stdout_file = string(tmp_dir) + "/stdout";
            string stderr_file = string(tmp_dir) + "/stderr";

            // execute the command "cmd > stdout_file 2> stderr_file"
            string cli = cmd + " > " + stdout_file + " 2> " + stderr_file;
            exit_code_ = system(cli.c_str());
            exit_code_ = WEXITSTATUS(exit_code_);
            stdout_str_ = File2Str(stdout_file);
            stderr_str_ = File2Str(stderr_file);

            // rid of the temp files
            remove(stdout_file.c_str());
            remove(stderr_file.c_str());
            remove(tmp_dir);

            return exit_code_;
        }

    private:
        int exit_code_;
        string stderr_str_;
        string stdout_str_;

        /**
         * @brief read a file
         * 
         * @param file_name: file path 
         * @return string the contents of the file.
         */
        string File2Str(string file_name) {
            ifstream file;
            stringstream str_stream;

            file.open(file_name);
            if (file.is_open()) {
                str_stream << file.rdbuf();
                file.close();
            }
            return str_stream.str();
        }
};
#endif
#endif