import os
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

# Configuración de estilo
sns.set_theme(style="whitegrid")

def main():
    # Rutas de entrada y salida
    base_dir = os.path.dirname(os.path.abspath(__file__))
    csv_path = os.path.abspath(os.path.join(base_dir, "../data/measurements/results.csv"))
    plots_dir = os.path.abspath(os.path.join(base_dir, "../data/plots"))
    
    os.makedirs(plots_dir, exist_ok=True)

    if not os.path.exists(csv_path):
        print(f"Error: No se encontro el archivo {csv_path}")
        return

    df = pd.read_csv(csv_path)

    # Promediar las muestras 'a', 'b', 'c' para cada combinación
    df_avg = df.groupby(['algorithm', 'n', 'type', 'domain'], as_index=False).agg({
        'time_ms': 'mean',
        'memory_kb': 'mean'
    })

    tipos = df_avg['type'].unique()
    dominios = df_avg['domain'].unique()

    # Generar gráficos de Tiempo vs n
    for t in tipos:
        for d in dominios:
            sub_df = df_avg[(df_avg['type'] == t) & (df_avg['domain'] == d)]
            if sub_df.empty:
                continue

            plt.figure(figsize=(9, 6))
            sns.lineplot(data=sub_df, x='n', y='time_ms', hue='algorithm', marker='o', linewidth=2)
            
            plt.xscale('log')
            plt.yscale('log')
            plt.title(f'Tiempo de Ejecucion vs Tamano (Tipo: {t}, Dominio: {d})', fontsize=12)
            plt.xlabel('Tamano del arreglo (n)', fontsize=10)
            plt.ylabel('Tiempo (ms) [Escala Log]', fontsize=10)
            plt.tight_layout()

            plot_path = os.path.join(plots_dir, f'time_{t}_{d}.png')
            plt.savefig(plot_path, dpi=300)
            plt.close()
            print(f'Grafico guardado: {plot_path}')

    # Generar gráficos de Memoria vs n 
    for t in tipos:
        for d in dominios:
            sub_df = df_avg[(df_avg['type'] == t) & (df_avg['domain'] == d)]
            if sub_df.empty:
                continue

            plt.figure(figsize=(9, 6))
            sns.lineplot(data=sub_df, x='n', y='memory_kb', hue='algorithm', marker='s', linewidth=2)
            
            plt.xscale('log')
            plt.title(f'Uso de Memoria Peak vs Tamano (Tipo: {t}, Dominio: {d})', fontsize=12)
            plt.xlabel('Tamano del arreglo (n)', fontsize=10)
            plt.ylabel('Memoria Peak (KB)', fontsize=10)
            plt.tight_layout()

            plot_path = os.path.join(plots_dir, f'memory_{t}_{d}.png')
            plt.savefig(plot_path, dpi=300)
            plt.close()
            print(f'Grafico de memoria guardado: {plot_path}')

main()