
#ifdef _WIN32

    #include <consoleutilities.h>
    #include <windows.h>

    void Ut_ClearConsole()
    {

        DWORD written;
        
        COORD topLeft = { 0, 0 };

        CONSOLE_SCREEN_BUFFER_INFO screen;
        
        HANDLE _standard_output_handler = GetStdHandle(STD_OUTPUT_HANDLE);

        GetConsoleScreenBufferInfo(_standard_output_handler, &screen);

        FillConsoleOutputCharacter(_standard_output_handler, TEXT(' '), screen.dwSize.X * screen.dwSize.Y, topLeft, &written);

        Ut_SetConsoleCursorPosition(0, 0);
    
    }

    void Ut_SetConsoleCursorPosition(int32_t x, int32_t y)
    {

        HANDLE _standard_output_handler = GetStdHandle(STD_OUTPUT_HANDLE);

        COORD _new_cursor_position = { (int16_t)x, (int16_t)y };
        
        SetConsoleCursorPosition(_standard_output_handler, _new_cursor_position);

    }

#endif
