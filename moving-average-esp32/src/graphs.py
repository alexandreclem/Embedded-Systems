import pandas as pd
import matplotlib.pyplot as plt


def main():
    # Loading the data
    data = pd.read_csv('data.csv')
    
    # Splitting the data v -> value | a -> moving average
    values = data[data['type'] == 'v']
    moving_average = data[data['type'] == 'a']
    
    # Adding a time (1 second at a time) column
    values_length = [i for i in range(len(values))]
    moving_average_length = [i for i in range(4, len(moving_average ) + 4)]
    values.insert(0, 'time', values_length, True)
    moving_average.insert(0, 'time', moving_average_length, True)
    
    # Plotting the data
    # Temperature
    axis = values.plot(kind='line', x='time', y='t', title='Temperature x Time')    
    moving_average.plot(kind='line', x='time', y='t', ax=axis)
    axis.set_xlabel('Time (s)')
    axis.set_ylabel('Temperature (°C)')
    axis.legend(['Values', 'Moving Average'], loc='upper left')

    # Humidity
    axis = values.plot(kind='line', x='time', y='h', title='Humidity x Time')    
    moving_average.plot(kind='line', x='time', y='h', ax=axis)
    axis.set_xlabel('Time (s)')
    axis.set_ylabel('Humidity (%)')   
    axis.legend(['Values', 'Moving Average'])

    plt.show()


if __name__ == '__main__':
    main()