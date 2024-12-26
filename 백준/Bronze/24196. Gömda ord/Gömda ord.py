def decrypt_message(encrypted_message):
    # 출력 문자열을 저장할 변수
    decrypted_message = ""
    # 현재 위치를 저장할 변수
    current_position = 0

    # 복호화 알고리즘 실행
    while current_position < len(encrypted_message):
        # 현재 위치의 문자를 출력 문자열에 추가
        current_char = encrypted_message[current_position]
        decrypted_message += current_char
        
        # 다음 이동 거리를 계산 (A=1, B=2, ..., Z=26)
        move_distance = ord(current_char) - ord('A') + 1
        
        # 다음 위치로 이동
        current_position += move_distance
        
        # 마지막 문자에 도달하면 종료
        if current_position >= len(encrypted_message):
            break

    return decrypted_message

# 예제 실행
encrypted_message = input()
decrypted_message = decrypt_message(encrypted_message)
print(decrypted_message)
