
#ifdef _WIN32

    #include <terminalutilities.h>
    #include <windows.h>

    HANDLE _standard_output_handler;

    void SetTerminalCursorPosition(int32_t x, int32_t y)
    {

        _standard_output_handler = GetStdHandle(STD_OUTPUT_HANDLE);

        COORD _new_cursor_position = { (int16_t)x, (int16_t)y };
        
        SetConsoleCursorPosition(_standard_output_handler, _new_cursor_position);

    }

    void ClearTerminal()
    {

        DWORD written;
        
        COORD topLeft = { 0, 0 };

        CONSOLE_SCREEN_BUFFER_INFO screen;
        
        _standard_output_handler = GetStdHandle(STD_OUTPUT_HANDLE);

        GetConsoleScreenBufferInfo(_standard_output_handler, &screen);

        FillConsoleOutputCharacter(_standard_output_handler, TEXT(' '), screen.dwSize.X * screen.dwSize.Y, topLeft, &written);

        SetTerminalCursorPosition(0, 0);
    
    }

#endif
