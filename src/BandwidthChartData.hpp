#ifndef BANDWIDTH_CHART_DATA_H
#define BANDWIDTH_CHART_DATA_H

#include <QtCore/QObject>
#include <QtCharts/QAbstractSeries>

/**
 * A helper class for dealing with QML charts. Maintains a dataset of recent
 * bandwidth utilization samples and provides a means to update a data series
 * efficiently (I hope).
 */
class BandwidthChartData : public QObject
{
    Q_OBJECT
public:
    explicit BandwidthChartData(QObject *parent = nullptr);

    /**
     * Update the dataset with a new upload utilization sample
     */
    Q_INVOKABLE void addUploadSample(qreal sample);

    /**
     * Update the dataset with a new download utilization sample
     */
    Q_INVOKABLE void addDownloadSample(qreal sample);

    /**
     * Update the provided series with our chart data
     */
    Q_INVOKABLE void updateUploadSeries(QtCharts::QAbstractSeries *series);
    Q_INVOKABLE void updateDownloadSeries(QtCharts::QAbstractSeries *series);

    /**
     * Get the highest samples currently being tracked
     */
    Q_INVOKABLE int getHighestUploadSample();
    Q_INVOKABLE int getHighestDownloadSample();

    /**
     * Get the greater of the highest upload or highest download samples
     */
    Q_INVOKABLE int getHighestSample();

private:

    uint64_t m_numSamples;
    QVector<QPointF> m_uploadSamples;
    QVector<QPointF> m_downloadSamples;

    int64_t m_highestUploadSample = 0;
    int64_t m_highestDownloadSample = 0;

};

#endif // BANDWIDTH_CHART_DATA_H

