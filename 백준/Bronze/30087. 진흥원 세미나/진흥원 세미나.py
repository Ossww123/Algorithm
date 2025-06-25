data_dict = {
    'Algorithm': '204',
    'DataAnalysis': '207', 
    'ArtificialIntelligence': '302',
    'CyberSecurity': 'B101',
    'Network': '303',
    'Startup': '501',
    'TestStrategy': '105'
}

n = int(input())
for i in range(n):
    a = input()
    print(data_dict[a])