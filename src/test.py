import os
import sys

def compare_files_byte_by_byte(file1_path, file2_path):
    with open(file1_path, 'rb') as f1, open(file2_path, 'rb') as f2:
        if f1.seek(0, 2) != f2.seek(0, 2):
            return False
        f1.seek(0)
        f2.seek(0)
        chunk_size = 8192
        while True:
            chunk1 = f1.read(chunk_size)
            chunk2 = f2.read(chunk_size)
            if chunk1 != chunk2:
                return False
            if not chunk1:
                return True

def compare_txt_files_in_test_folders(test_folder):
    tot = 0
    right = 0
    
    # 获取 test 文件夹下所有以 'test' 开头的文件夹
    test_subfolders = [d for d in os.listdir(test_folder) if os.path.isdir(os.path.join(test_folder, d)) and d.startswith('test')]
    
    for subfolder in test_subfolders:
        output_file = os.path.join(test_folder, subfolder, 'output.txt')
        expected_output_file = os.path.join(test_folder, subfolder, 'expected_output.txt')
        
        if not os.path.exists(output_file) or not os.path.exists(expected_output_file):
            print(f"警告: {subfolder} 中缺少 output.txt 或 expected_output.txt")
            continue
        
        tot += 1
        
        if compare_files_byte_by_byte(output_file, expected_output_file):
            print(f"{subfolder}: 文件相同")
            right += 1
        else:
            print(f"{subfolder}: 文件不同")
            
            # 可选：如果文件不同，打印具体的差异
            # with open(output_file, 'r') as f1, open(expected_output_file, 'r') as f2:
            #     output_data = f1.read()
            #     expected_data = f2.read()
            #     print(f"  output.txt 中的内容: {output_data}")
            #     print(f"  expected_output.txt 中的内容: {expected_data}")

    print(f"\n一共运行了 {tot} 组")
    print(f"正确 {right} 组")
    if tot==right:
        print("该功能完全正确！")
    else:
        print("该功能不完全正确！")

# 执行比较
if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("使用方法: python script_name.py <test_folder_path>")
        sys.exit(1)
    
    test_folder = sys.argv[1]
    if not os.path.isdir(test_folder):
        print(f"错误: {test_folder} 不是一个有效的目录")
        sys.exit(1)
    
    # 执行比较
    compare_txt_files_in_test_folders(test_folder)