﻿using System.ComponentModel;
using System.Runtime.Serialization;

namespace KawaiiEditor
{
    /// <summary>
    /// Base class for all view models in this project, that implements INotifyPropertyChanged
    /// for each view model
    /// </summary>
    [DataContract(IsReference = true)]
    public class ViewModelBase : INotifyPropertyChanged
    {
        public event PropertyChangedEventHandler PropertyChanged;

        protected void OnPropertyChanged(string propertyChanged)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyChanged));
        }
    }
}
